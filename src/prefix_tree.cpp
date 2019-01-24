#pragma once

#include "prefix_tree.hpp"

#include <algorithm>


PrefixTree::~PrefixTree() {
	_DisposeMemory(_root);
}


void PrefixTree::_DisposeMemory(PrefixTree::_Node *ptr) noexcept {
	if(ptr != nullptr) {
		for(const auto &it : ptr->_child_nodes) {
			_DisposeMemory(it.second);
		}
		delete ptr;
	}
}


PrefixTree::_Node* PrefixTree::SkipToPrefixEnd(const std::string &prefix) const noexcept {
	_Node *ptr = _root;
	for(const char c : prefix)	{
		_Node* cnode = _FindSymbolNodeAddress(c, ptr->_child_nodes);
		if(cnode == nullptr) {
			return nullptr;
		}
		else {
			ptr = cnode;
		}
	}
	return ptr;
}


PrefixTree::_Node* PrefixTree::_FindSymbolNodeAddress(const char symbol, 
		const _Node::ChildrenContainer &nodes) const noexcept {
	for(const auto &it : nodes) {
		if(it.first == symbol) return it.second;
	}
	return nullptr;
}
