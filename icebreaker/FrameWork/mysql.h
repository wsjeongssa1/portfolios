//#pragma once
//#include "Include.h"
//
//struct Rank
//{
//	char first[10];
//	char middle[10];
//	char last[10];
//	char score[10];
//};
//class Mysql
//{
//
//public:
//	Mysql();
//	~Mysql();
//
//	// MYSQL ����ü ���� (Logo é�Ϳ��� 1 �ܰ� �׽�Ʈ ���� Ȯ���� ����...)
//	MYSQL mysql;
//
//	// MYSQL ���� �� ���� ����
//	MYSQL		*connection = NULL, conn;
//	MYSQL_RES	*sql_result;
//	MYSQL_ROW	sql_row;
//	int query_start;
//
//	 ����Ÿ ���̽� Į�� ���� ����
//	char first[10];
//	char middle[10];
//	char last[10];
//	char score[200];
//
//	char query[255];
//
//	 MYSQL ���� ����
//	char state[256];
//	bool mysql_Success;
//
//	 MYSQL ��� Ȯ�� ����
//	Rank ranking[8];
//
//	void Init();
//	void Update(double frame);
//	void Draw();
//	void save();
//};
//
//extern Mysql sql;