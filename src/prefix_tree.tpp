#pragma once


template<typename String>
void PrefixTree::AddString(const String& string) {
	AddString(std::begin(string), std::end(string));
}


template<typename Iterator>
void PrefixTree::AddString(Iterator begin, Iterator end) {
	if(_root == nullptr) {
		_root = new _Node;
	}
	_Node *ptr = _root;
	for(; begin != end; ++begin) {
		char c{ *begin };
		_Node *cnode = _FindSymbolNodeAddress(c, ptr->_child_nodes);
		if(cnode == nullptr) { // if we haven't got child for such prefix, create it
			_Node *temp = new _Node();
			ptr->_child_nodes.push_front({ c, temp });
			ptr = temp;
		}
		else { // if we got such prefix, just go to child node
			ptr = cnode;
		}
	}
	ptr->_is_last_node = true;
}


template<typename OutputIterator>
void PrefixTree::SearchByPrefix(const std::string &prefix, OutputIterator out_iter) {
	if(_Node *ptr = SkipToPrefixEnd(prefix)) { // if we got such prefix
		std::string prefix_copy = prefix;
		_GoSearch(ptr, out_iter, prefix_copy);
	}
}

// TODO: write non-recursive version
template<typename OutputIterator>
void PrefixTree::_GoSearch(_Node *ptr, OutputIterator out_iter, std::string &str) {
	// if current prefix is the end for some string
	if(ptr->_is_last_node) {
		*out_iter++ = str;
	}

	for(const std::pair<char, _Node*> &it : ptr->_child_nodes) {
		str.push_back(it.first);
		_GoSearch(it.second, out_iter, str);
		str.pop_back();
	}
}
