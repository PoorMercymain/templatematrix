#pragma once

class column
{
	int current_column = -1;
	int currenttimecol = 0;
	int current_head = -1;
	int head_position = -1;
public:
	int getcurrent_column() { return current_column; }
	int getcurrenttimecol() { return currenttimecol; }
	int getcurrent_head() { return current_head; }
	int gethead_position() { return head_position; }
	void setcurrent_column(int value) { current_column = value; }
	void setcurrenttimecol(int value) { currenttimecol = value; }
	void setcurrent_head(int value) { current_head = value; }
	void sethead_position(int value) { head_position = value; }
};

