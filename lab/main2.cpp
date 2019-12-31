#include<direct.h>
#include<time.h>
#include "data_done.h"

using namespace std;

const char c[7][30] = {{"../data/edge2015_1.csv"},{"../data/edge2015_2.csv"},{"../data/edge2016_1.csv"},{"../data/edge2016_2.csv"},{"../data/edge2017_1.csv"},{"../data/edge2017_2.csv"},{"../data/edge2018_1.csv"}};

const char head[15] = "../result/";

const char tail[10] = ".csv";

map<Node,float> table1;
map<Node,float> table2;
map<Node,float> table3;

char name[5];

int main(){
	int begin,end;
	
	begin = clock();
	
	char *file_name = NULL;

	get_data(c[0],table1);
	
	for(int i = 1;i < 7;i++)
	{
		get_data(c[1],table2);
	
		sprintf(name,"%d",i);
		
		file_name = get_fileName(head,name,tail);
		
		make_data(table1,table2,table3);
		
		write_file(file_name,table3);
		
		table1.erase(table1.begin(),table1.end());
		table2.erase(table2.begin(),table2.end());
		table3.erase(table3.begin(),table3.end());
		
		get_data(file_name,table1);
		
		free(file_name);
	
	}
	
	end = clock();
	
	printf("Running Time: %d ms\n",end - begin);

	return 0;
}
