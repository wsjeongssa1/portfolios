//#include "mysql.h"
//#define _CRT_NONSTDC_NO_DEPRECATE 
//Mysql sql;
//
//Mysql::Mysql()
//{
//}
//
//Mysql::~Mysql()
//{
//}
//
//void Mysql::Init()
//{
//}
//
//void Mysql::Update(double frame)
//{
//}
//
//void Mysql::Draw()
//{
//	// ����Ÿ ���̽� ó�� ���� ǥ��/////////////////////////////////////
//	if (sql.mysql_Success)
//	{
//		dv_font.DrawString("Success", 550, 0);
//	}
//	else
//	{
//		dv_font.DrawString("Error", 500, 0);
//		dv_font.DrawString(sql.state, 700, 0);
//	}
//	//////////////////////////////////////////////////////////
//}
//
//void Mysql::save()
//{
//	///// ���� ����� ���////////////////////
//	 insert Value
//	 �̸�
//	fgets(name, 12, stdin);
//	CHOP(name);
//
//	 ��й�ȣ
//	fgets(address, 80, stdin);
//	CHOP(address);
//	//////////////////////////////////////////
//
//	// �츰 ������ �ڽ��� �ʿ�////////////////
//
//	// ���̺� ���� �� �Է�
//	sprintf_s(first, "%d", playdata.p1_name[0]);
//	sprintf_s(middle, "%d", playdata.p1_name[1]);
//	sprintf_s(last, "%d", playdata.p1_name[2]);
//	sprintf_s(score, "%d", playdata.p1_total_score);
//	// ���� �� ������ ����
//	sprintf_s(query, "insert into rank values "
//		"('%s','%s','%s','%s')", first, middle, last, score);
//	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
//	query_start = mysql_query(connection, query);
//	// ���̺� ���� �� �Է�
//	sprintf_s(first, "%d", playdata.p2_name[0]);
//	sprintf_s(middle, "%d", playdata.p2_name[1]);
//	sprintf_s(last, "%d", playdata.p2_name[2]);
//	sprintf_s(score, "%d", playdata.p2_total_score);
//	// ���� �� ������ ����
//	sprintf_s(query, "insert into rank values "
//		"('%s','%s','%s','%s')", first, middle, last, score);
//	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
//	query_start = mysql_query(connection, query);
//
//	if (query_start != 0) // ���� ���н�
//	{
//		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
//		sql.mysql_Success = false;
//	}
//	else // ������
//	{
//		mysql_Success = true;
//	}
//}
///*
//Mysql �����ϱ�
//* 64 ��Ʈ�� ��� 64 ��Ʈ ���� �� ������.
//* ���� ���͸��� C:\Program Files\MySQL\MySQL Server 5.7\include �� �߰�
//* ���̺귯�� ���͸��� C:\Program Files\MySQL\MySQL Server 5.7\lib �߰�
//* ��Ŀ ���� libmysql.lib
//* C:\Program Files\MySQL\MySQL Server 5.7\lib �ȿ� libmysql.dll ���� �� ������ ������Ʈ ������ �����ֱ�
//
//mysql ���� �Լ��� ����ϸ鼭 ������ �߻�?????.
//�� mysql.h�� ������ ����, �� �Լ����� ���ǵǾ� �ִ� ����(���̺귯���� ���ǵǾ� �ֽ��ϴ�.)�� ã�� �� ���ٴ� �����̴�.
//�츮 ���� ȯ���� ������7 64Bit �Դϴ�.
//������ ������ ����� ���� 64 ��Ʈ�� �����Դϴ�.
//ȯ���� 64��Ʈ�̴� �и� mysql ��ġ�� ���� 64��Ʈ�� �����Ͽ� ��ġ�߽��ϴ�.
//�׷���? �츮�� ����ϰ� �ִ� ����� ��Ʃ���, �� ���� ȯ���� 32��Ʈ�Դϴ�.
//���� ȯ���� 64��Ʈ�� �ٲ��ָ� ������ ������ϴ�.
//
//*/