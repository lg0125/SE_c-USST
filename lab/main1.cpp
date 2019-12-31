#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<direct.h>
#include<map>
#include<string>
#include "data_done.h"

using namespace std;

const char c[7][30] = {{"../data/edge2015_1.csv"},{"../data/edge2015_2.csv"},{"../data/edge2016_1.csv"},{"../data/edge2016_2.csv"},{"../data/edge2017_1.csv"},{"../data/edge2017_2.csv"},{"../data/edge2018_1.csv"}};

map<Node,float> table; 

int main(){
	FILE *fp = NULL;
	char *line = NULL;
	//char *record = NULL;
	char buffer[1024] = {""};
	char **_data;
	string _source;
	string _target;
	int size = 0;

	if((fp = fopen(c[0],"at+"))!=NULL)
	{
		fseek(fp,22,SEEK_SET);

		int j = 0;

		while((line = fgets(buffer,sizeof(buffer),fp))!=NULL)
		{
			if(line[strlen(line) - 1] == '\n')
			{
				line[strlen(line) - 1] = '\0';
			}
	
			_data = explode(',',line,&size);

			for(int i = 0;i < size;i++)
			{
				if(i != size - 1)
				{
					printf("%s ",_data[i]);
				}
				else
				{
					printf("%s\n",_data[i]);
				
				}
			}
			
			Node node;
			float _weight;
			
			for(int i = 0;i<size;i++){
				if(i == 0){
					strcpy(node.source,_data[i]);
				}else if(i == 1){
					strcpy(node.target,_data[i]);
				}else if(i == 2){
					_weight = sigmoid(atof(_data[i]));
				}
			}
			
			table.insert(pair<Node,float>(node,_weight));
			
			freeExplode(_data,size);	

			if(j == 100) break;
			j++;

		}

		fclose(fp);
		fp = NULL;

	}	
	
	printf("-------------\n");
	

	for(map<Node,float>::iterator it=table.begin();it!=table.end();(it)++)
	{
		printf("%s ",it->first.source);
		printf("%s ",it->first.target);
		printf("%f\n",it->second);
	
	}
	return 0;
}
