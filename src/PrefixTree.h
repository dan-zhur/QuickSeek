#pragma once

#include "Config.h"
#include <QChar>
#include <atomic>
#include <forward_list>
#include <list>
#include <thread>

class PrefixTree
{
public:
	//types
	using Char = config::Char;
	using String = config::String;
	//------------------------------

	//construction / deletion
	PrefixTree() = default;
	~PrefixTree();
	//------------------------------

	//methods
	template<typename Container>
	void AddString(const Container& container);

	template<typename Iterator>
	void AddString(Iterator begin, Iterator end);

	template<typename Function>
	void SearchByPrefix(const String& prefix, Function callback);

	void StopSearch();

	void WaitSearch();
	//------------------------------
private:
	//types
	struct Node_ {
		bool isEndingNode_{ false }; //€вл€етс€ ли последним дл€ некоторого префикса
		std::forward_list< std::pair<Char, Node_*> > nextNodes_;
	};
	//------------------------------

	//methods
	void DeleteMemory_(Node_* ptr);

	/*
	ѕроходит по строке, заданному итераторами и одновременно такой же путь
	делает в дереве. 
	¬ случае успеха, возвращает указатель на Node_, содержащий последний
	символ строки. ¬ случае, если такой префикс не найден, возвращает nullptr.
	*/
	Node_* SkipToPrefixEnd(const String& prefix);

	/*
	ƒл€ дл€ префикса, заканчивающемс€ в *ptr, вызывает callback(begin, end),
	где begin, end - итераторы дл€ коллекции Char (котора€ представл€ет собой
	строку в дереве).
	*/
	template<typename Function>
	void SearchByPrefixHelper_(String prefix, Function callback);

	template<typename Function>
	void GoSearch_(Node_* ptr, Function callback, String& str);

	Node_* FindSymbolNodeAddress_(Char symbol, const std::forward_list<std::pair<Char, Node_*>>& nodes);
	//------------------------------


	//member variables
	Node_ *root_{ nullptr };
	std::atomic<bool> stopSearch_{ false }, isSearchRunning_{ false };
	std::thread searchThread_;
	//------------------------------
};


#include "PrefixTree.tcc"