#pragma once
class Data
{
private:

public:
	char p1_name[3];
	int p1_seal_count;
	int p1_block_count;
	int p1_total_score;
	bool namecheck1 = false;

	char p2_name[3];
	int p2_seal_count;
	int p2_block_count;
	int p2_total_score;
	bool namecheck2 = false;

	int winner;
	bool load_ = true;
	Data();
	~Data();

	void Reset();
};

extern Data playdata;