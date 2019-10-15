#pragma once
#include"Include.h"

Data playdata;

Data::Data()
{
	winner = 0;

	p1_name[0] = 'A';
	p1_name[1] = 'A';
	p1_name[2] = 'A';
	p1_seal_count = 0;
	p1_block_count = 0;
	p1_total_score = 0;

	p2_name[0] = 'A';
	p2_name[1] = 'A';
	p2_name[2] = 'A';
	p2_seal_count = 0;
	p2_block_count = 0;
	p2_total_score = 0;
}

Data::~Data()
{
}

void Data::Reset()
{
	winner = 0;

	p1_seal_count = 0;
	p1_block_count = 0;
	p1_total_score = 0;

	p2_seal_count = 0;
	p2_block_count = 0;
	p2_total_score = 0;
}
