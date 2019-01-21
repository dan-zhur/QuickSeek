#pragma once

template<typename Container>
void PrefixTree::AddString(const Container& container) {
	AddString(std::begin(container), std::end(container));
}


template<typename Iterator>
void PrefixTree::AddString(Iterator begin, Iterator end) {
	if(_root == nullptr) {
		_root = new _Node;
	}
	_Node *ptr = _root;
	for(; begin != end; ++begin) {
		std::string c{ *begin };
		_Node* cnode = FindSymbolNodeAddress_(c, ptr->_child_nodes);
		if(cnode == nullptr) { //если нет, то добавляем букву, чтобы был node
			_Node *temp = new _Node();
			ptr->_child_nodes.push_front(std::make_pair(c, temp));
			ptr = temp;
		}
		else { //если префикс в дереве есть, то просто переходим по указателю на следующую букву
			ptr = cnode;
		}
	}
	ptr->_is_last_node = true;
}


template<typename Function>
void PrefixTree::SearchByPrefix(const std::string& prefix, Function callback) {
	_stop_search = false;
	_is_search_running = true;
	_search_thread = std::thread(&PrefixTree::SearchByPrefixHelper_<Function>, this, prefix, callback);
}



template<typename Function>
void PrefixTree::SearchByPrefixHelper_(std::string prefix, Function callback) {
	_Node* ptr = SkipToPrefixEnd(prefix);
	if(ptr) { //если есть такой префикс
		GoSearch_(ptr, callback, prefix);
		callback(std::string{}); //показывает, что поиск завершен
		_is_search_running = false;
	}
}


//TODO: написать нерекурсивную версию
template<typename Function>
void PrefixTree::GoSearch_(_Node* ptr, Function callback, std::string& str) {
	//TODO: оптимизировать
	if(_stop_search.load()) {
		return;
	}

	//если в текущей вершине заканчивается некая строка
	if(ptr->_is_last_node) {
		callback(str);
	}

	for(const std::pair<std::string, _Node*>& it : ptr->_child_nodes) {
		std::string tmp = str;
		str.append(it.first);
		GoSearch_(it.second, callback, str);
		str = tmp;
	}
}
