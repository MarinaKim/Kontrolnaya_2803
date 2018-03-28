#pragma once

struct Group
{
	char *name;
	int *ses;

};

struct zavod
{
	char *name;
	int sr_age;
	char* prof;
	int sr_sal;
};

struct worker
{
	char *name;
	int age;
	char *prof;
	int sal;

};
void generateName(char *name);
