#pragma once


template<typename Container>
void PrefixTree::AddString(const Container &container) {
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
		_Node *cnode = _FindSymbolNodeAddress(c, ptr->_child_nodes);
		if(cnode == nullptr) { // if we haven't got child for such prefix, create it
			_Node *temp = new _Node();
			ptr->_child_nodes.push_front(std::make_pair(c, temp));
			ptr = temp;
		}
		else { // if we got such prefix, just go to child node
			ptr = cnode;
		}
	}
	ptr->_is_last_node = true;
}


template<typename Function>
void PrefixTree::SearchByPrefix(const std::string &prefix, Function callback) {
	_stop_search = false;
	_is_search_running = true;
	_search_thread = std::thread(&PrefixTree::_SearchByPrefixHelper<Function>, this, prefix, callback);
}


template<typename Function>
void PrefixTree::_SearchByPrefixHelper(std::string prefix, Function callback) {
	_Node *ptr = SkipToPrefixEnd(prefix);
	if(ptr) { // if we got such prefix
		_GoSearch(ptr, callback, prefix);
		callback(std::string{}); // shows that search is finished
		_is_search_running = false;
	}
}


// TODO: write non-recursive version
template<typename Function>
void PrefixTree::_GoSearch(_Node *ptr, Function callback, std::string &str) {
	// TODO: optimize
	if(_stop_search.load()) {
		return;
	}

	// if current prefix is the end for some string
	if(ptr->_is_last_node) {
		callback(str);
	}

	for(const std::pair<std::string, _Node*> &it : ptr->_child_nodes) {
		std::string tmp = str;
		str.append(it.first);
		_GoSearch(it.second, callback, str);
		str = tmp;
	}
}
