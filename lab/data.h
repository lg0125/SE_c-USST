#ifndef DATA_H
#define DATA_H

#include<map>
using namespace std;

struct Node
{
	char source[20];
	char target[20];
		
	bool operator<(const Node &rhs)const{
		if(strcmp(source,rhs.source)<0) return true;
		else if(strcmp(source,rhs.source)==0){
			if(strcmp(target,rhs.target)<0) return true;
		}
		return false;
	}
};

float sigmoid(float x);

char **explode(char sep,const char *str,unsigned int *size);

void freeExplode(char **arr, int size);

float alpha();

void get_data(const char* file_name,map<Node,float> &table);

char *get_fileName(const char *head,const char *name,const char *tail);

void make_data(map<Node,float> &table1,map<Node,float> &table2,map<Node,float> &table3);

void write_file(const char*file_name,const map<Node,float> &table);
#endif
