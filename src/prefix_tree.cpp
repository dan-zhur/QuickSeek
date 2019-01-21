#pragma once

#include "prefix_tree.hpp"

#include <algorithm>


PrefixTree::~PrefixTree() {
	StopSearch();
	DeleteMemory_(root_);
}


void PrefixTree::DeleteMemory_(PrefixTree::Node_* ptr) {
	if(ptr != nullptr) {
		for(const auto& it : ptr->nextNodes_) {
			DeleteMemory_(it.second);
		}
		delete ptr;
	}
}


void PrefixTree::StopSearch() {
	if(searchThread_.joinable()) {
		stopSearch_.store(true);
		searchThread_.join();
		stopSearch_.store(false);
	}
}


PrefixTree::Node_* PrefixTree::SkipToPrefixEnd(const std::string& prefix) {
	Node_* ptr = root_;
	for(const auto& c : prefix)	{
		Node_* cNode = FindSymbolNodeAddress_({ c }, ptr->nextNodes_);
		if(cNode == nullptr) {
			return nullptr;
		}
		else {
			ptr = cNode;
		}
	}
	return ptr;
}


PrefixTree::Node_* PrefixTree::FindSymbolNodeAddress_(const std::string& symbol, const std::forward_list<std::pair<std::string, Node_*>>& nodes) {
	for(const auto& it : nodes)	{
		if(it.first == symbol) {
			return it.second;
		}
	}
	return nullptr;
}


void PrefixTree::WaitSearch() {
	if(searchThread_.joinable()) {
		searchThread_.join();
	}
}
