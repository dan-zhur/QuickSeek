#pragma once

#include <atomic>
#include <forward_list>
#include <list>
#include <thread>


class PrefixTree {
public:
	// special members
	PrefixTree() = default;
	~PrefixTree();
	//------------------------------

	// methods
	template<typename Container>
	void AddString(const Container &container);

	template<typename Iterator>
	void AddString(Iterator begin, Iterator end);

	template<typename Function>
	void SearchByPrefix(const std::string &prefix, Function callback);

	void StopSearch();

	void WaitSearch();
	//------------------------------
private:
	// types
	struct _Node {
		bool _is_last_node{ false }; // if the node is the last for some prefix
		std::forward_list< std::pair<std::string, _Node*> > _child_nodes;
	};
	//------------------------------

	// methods
	void DeleteMemory_(_Node *ptr);

	/*
	Goes through tree by a way, defined by string.
	If succeeded, returns _Node*, pointing to last string symbol.
	If failed, returns nullptr.
	*/
	_Node* SkipToPrefixEnd(const std::string &prefix);

	/*
	For prefix, runs callback for all child nodes that are ends for
	some strings.
	*/
	template<typename Function>
	void SearchByPrefixHelper_(std::string prefix, Function callback);

	template<typename Function>
	void GoSearch_(_Node *ptr, Function callback, std::string &str);

	_Node* FindSymbolNodeAddress_(const std::string &symbol, const std::forward_list<std::pair<std::string, _Node*>> &nodes);
	//------------------------------


	// member variables
	_Node *_root{ nullptr };
	std::atomic<bool> _stop_search{ false }, _is_search_running{ false };
	std::thread _search_thread;
	//------------------------------
};


#include "prefix_tree.tpp"
