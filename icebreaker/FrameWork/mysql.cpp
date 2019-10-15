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
//	// 데이타 베이스 처리 상태 표시/////////////////////////////////////
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
//	///// 도스 모드인 경우////////////////////
//	 insert Value
//	 이름
//	fgets(name, 12, stdin);
//	CHOP(name);
//
//	 비밀번호
//	fgets(address, 80, stdin);
//	CHOP(address);
//	//////////////////////////////////////////
//
//	// 우린 에디터 박스가 필요////////////////
//
//	// 테이블 저장 값 입력
//	sprintf_s(first, "%d", playdata.p1_name[0]);
//	sprintf_s(middle, "%d", playdata.p1_name[1]);
//	sprintf_s(last, "%d", playdata.p1_name[2]);
//	sprintf_s(score, "%d", playdata.p1_total_score);
//	// 전달 할 쿼리값 셋팅
//	sprintf_s(query, "insert into rank values "
//		"('%s','%s','%s','%s')", first, middle, last, score);
//	// 다음 mysql_query() 함수로 MYSQL 구조체를 통한 쿼리문 전송
//	query_start = mysql_query(connection, query);
//	// 테이블 저장 값 입력
//	sprintf_s(first, "%d", playdata.p2_name[0]);
//	sprintf_s(middle, "%d", playdata.p2_name[1]);
//	sprintf_s(last, "%d", playdata.p2_name[2]);
//	sprintf_s(score, "%d", playdata.p2_total_score);
//	// 전달 할 쿼리값 셋팅
//	sprintf_s(query, "insert into rank values "
//		"('%s','%s','%s','%s')", first, middle, last, score);
//	// 다음 mysql_query() 함수로 MYSQL 구조체를 통한 쿼리문 전송
//	query_start = mysql_query(connection, query);
//
//	if (query_start != 0) // 전송 실패시
//	{
//		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
//		sql.mysql_Success = false;
//	}
//	else // 성공시
//	{
//		mysql_Success = true;
//	}
//}
///*
//Mysql 연동하기
//* 64 비트인 경우 64 비트 설정 꼭 해주자.
//* 포함 디렉터리에 C:\Program Files\MySQL\MySQL Server 5.7\include 를 추가
//* 라이브러리 디렉터리에 C:\Program Files\MySQL\MySQL Server 5.7\lib 추가
//* 링커 편집 libmysql.lib
//* C:\Program Files\MySQL\MySQL Server 5.7\lib 안에 libmysql.dll 복사 후 파일을 프로젝트 폴더에 붙혀넣기
//
//mysql 관련 함수를 사용하면서 에러가 발생?????.
//즉 mysql.h를 참조만 했지, 그 함수들이 정의되어 있는 파일(라이브러리에 정의되어 있습니다.)을 찾을 수 없다는 오류이다.
//우리 개발 환경은 윈도우7 64Bit 입니다.
//윈도우 버전은 상관이 없고 64 비트가 문제입니다.
//환경이 64비트이니 분명 mysql 설치할 때도 64비트를 선택하여 설치했습니다.
//그러나? 우리가 사용하고 있는 비쥬얼 스튜디오, 이 개발 환경은 32비트입니다.
//개발 환경을 64비트로 바꿔주면 오류는 사라집니다.
//
//*/