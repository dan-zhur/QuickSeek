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
		bool isEndingNode_{ false }; //�������� �� ��������� ��� ���������� ��������
		std::forward_list< std::pair<Char, Node_*> > nextNodes_;
	};
	//------------------------------

	//methods
	void DeleteMemory_(Node_* ptr);

	/*
	�������� �� ������, ��������� ����������� � ������������ ����� �� ����
	������ � ������. 
	� ������ ������, ���������� ��������� �� Node_, ���������� ���������
	������ ������. � ������, ���� ����� ������� �� ������, ���������� nullptr.
	*/
	Node_* SkipToPrefixEnd(const String& prefix);

	/*
	��� ��� ��������, ��������������� � *ptr, �������� callback(begin, end),
	��� begin, end - ��������� ��� ��������� Char (������� ������������ �����
	������ � ������).
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