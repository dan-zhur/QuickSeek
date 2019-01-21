#pragma once

#include "prefix_tree.hpp"

#include <algorithm>


PrefixTree::~PrefixTree() {
	StopSearch();
	DeleteMemory_(_root);
}


void PrefixTree::DeleteMemory_(PrefixTree::_Node *ptr) {
	if(ptr != nullptr) {
		for(const auto &it : ptr->_child_nodes) {
			DeleteMemory_(it.second);
		}
		delete ptr;
	}
}


void PrefixTree::StopSearch() {
	if(_search_thread.joinable()) {
		_stop_search.store(true);
		_search_thread.join();
		_stop_search.store(false);
	}
}


PrefixTree::_Node* PrefixTree::SkipToPrefixEnd(const std::string &prefix) {
	_Node *ptr = _root;
	for(const auto &c : prefix)	{
		_Node* cnode = FindSymbolNodeAddress_({ c }, ptr->_child_nodes);
		if(cnode == nullptr) {
			return nullptr;
		}
		else {
			ptr = cnode;
		}
	}
	return ptr;
}


PrefixTree::_Node* PrefixTree::FindSymbolNodeAddress_(const std::string &symbol, const std::forward_list<std::pair<std::string, _Node*>> &nodes) {
	for(const auto &it : nodes)	{
		if(it.first == symbol) {
			return it.second;
		}
	}
	return nullptr;
}


void PrefixTree::WaitSearch() {
	if(_search_thread.joinable()) {
		_search_thread.join();
	}
}
