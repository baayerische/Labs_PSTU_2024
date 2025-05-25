#pragma once
#include <fstream>
#include "Money.h"
using namespace std;

int make_file(const char* f_name);
int print_file(const char* f_name);
int del_range_file(const char* f_name, const Money& k1, const Money& k2);
int double_value_file(const char* f_name, const Money& m);
int add_begin_file(const char* f_name, int k, const Money& m);