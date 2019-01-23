#pragma once

#include <atomic>
#include <forward_list>
#include <list>
#include <thread>


class PrefixTree final {
public:
	// special members
	PrefixTree() = default;
	PrefixTree(const PrefixTree&) = delete;
	PrefixTree(PrefixTree&&) = default;
	PrefixTree& operator=(const PrefixTree&) = delete;
	PrefixTree& operator=(PrefixTree&&) = default;
	~PrefixTree();
	//------------------------------

	// methods
	template<typename String>
	void AddString(const String &string);

	template<typename Iterator>
	void AddString(Iterator begin, Iterator end);

	template<typename OutputIterator>
	void SearchByPrefix(const std::string &prefix, OutputIterator out_iter);
	//------------------------------
private:
	// types
	struct _Node {
		using ChildrenContainer = std::forward_list< std::pair<char, _Node*> >;

		bool _is_last_node{ false }; // if the node is the last for some prefix
		ChildrenContainer _child_nodes;
	};
	//------------------------------

	// methods
	void _DisposeMemory(_Node *ptr);

	/*
	Goes through a tree by a way, defined by string.
	If succeeded, returns _Node*, pointing to last string symbol.
	If failed, returns nullptr.
	*/
	_Node* SkipToPrefixEnd(const std::string &prefix);

	/*
	Writes to out_iter all file names, that are children of ptr.
	*/
	template<typename OutputIterator>
	void _GoSearch(_Node *ptr, OutputIterator out_iter, std::string &str);

	_Node* _FindSymbolNodeAddress(const char symbol, const _Node::ChildrenContainer &nodes);
	//------------------------------


	// member variables
	_Node *_root{ nullptr };
	//------------------------------
};


#include "prefix_tree.tpp"
