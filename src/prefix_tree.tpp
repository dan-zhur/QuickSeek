#pragma once

template<typename Container>
void PrefixTree::AddString(const Container& container) {
	AddString(std::begin(container), std::end(container));
}


template<typename Iterator>
void PrefixTree::AddString(Iterator begin, Iterator end) {
	if(root_ == nullptr) {
		root_ = new Node_;
	}
	Node_ *ptr = root_;
	for(; begin != end; ++begin) {
		std::string c{ *begin };
		Node_* cNode = FindSymbolNodeAddress_(c, ptr->nextNodes_);
		if(cNode == nullptr) { //если нет, то добавляем букву, чтобы был node
			Node_ *temp = new Node_();
			ptr->nextNodes_.push_front(std::make_pair(c, temp));
			ptr = temp;
		}
		else { //если префикс в дереве есть, то просто переходим по указателю на следующую букву
			ptr = cNode;
		}
	}
	ptr->isEndingNode_ = true;
}


template<typename Function>
void PrefixTree::SearchByPrefix(const std::string& prefix, Function callback) {
	stopSearch_ = false;
	isSearchRunning_ = true;
	searchThread_ = std::thread(&PrefixTree::SearchByPrefixHelper_<Function>, this, prefix, callback);
}



template<typename Function>
void PrefixTree::SearchByPrefixHelper_(std::string prefix, Function callback) {
	Node_* ptr = SkipToPrefixEnd(prefix);
	if(ptr) { //если есть такой префикс
		GoSearch_(ptr, callback, prefix);
		callback(std::string{}); //показывает, что поиск завершен
		isSearchRunning_ = false;
	}
}


//TODO: написать нерекурсивную версию
template<typename Function>
void PrefixTree::GoSearch_(Node_* ptr, Function callback, std::string& str) {
	//TODO: оптимизировать
	if(stopSearch_.load()) {
		return;
	}

	//если в текущей вершине заканчивается некая строка
	if(ptr->isEndingNode_) {
		callback(str);
	}

	for(const std::pair<std::string, Node_*>& it : ptr->nextNodes_) {
		std::string tmp = str;
		str.append(it.first);
		GoSearch_(it.second, callback, str);
		str = tmp;
	}
}
