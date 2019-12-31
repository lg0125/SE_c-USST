#ifndef DATA_DONE_H
#define DATA_DONE_H

#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include"data.h"

float sigmoid(float x)
{
	return (float)(1/(1+exp(-x)));	
}

char **explode(char sep,const char *str,int *size)
{
	int i,count=0;

	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==sep) count++;
	}

	char **ret =(char **) calloc(++count,sizeof(char *));

	int last_index = -1;
	int j = 0;

	for(i = 0;i < strlen(str);i++)
	{
		if(str[i] == sep)
		{
			ret[j] = (char *)calloc(i - last_index,sizeof(char));
			memcpy(ret[j],str + last_index + 1, i - last_index - 1);
			j++;
			last_index = i;
		}
	}
	
	if(last_index <= strlen(str) - 1)
	{
		ret[j] = (char *)calloc(strlen(str) - last_index, sizeof(char));
		memcpy(ret[j], str + last_index + 1, strlen(str) - 1 - last_index);
		j++;
	}

	*size = j;

	return ret;
}

void freeExplode(char **arr,int size)
{
	int i;
	for(i = 0;i < size;i++)
	{
		free(arr[i]);
	}
	free(arr);
}

float alpha()
{
	return 0.5;
}

void get_data(const char *file_name,map<Node,float> &table)
{
	FILE *fp = NULL;
	char *line = NULL;
	char buffer[1024] = {""};
	char **_data = NULL;
	int size = 0;
	
	if((fp = fopen(file_name,"at+"))!=NULL)
	{
		fseek(fp,23,SEEK_SET);
		
		int j = 0;

		while((line = fgets(buffer,sizeof(buffer),fp))!=NULL)
		{
			if(line[strlen(line) - 1] == '\n')
			{
				line[strlen(line) - 1] = '\0';
			}
			
			_data = explode(',',line,&size);

			Node node;
			float _weight;

			for(int i = 0;i < size;i++)
			{
				if(i == 0) strcpy(node.source,_data[i]);
				else if(i == 1) strcpy(node.target,_data[i]);
				else if(i == 2) _weight = sigmoid(atof(_data[i]));				
			}

			table.insert(pair<Node,float>(node,_weight));
			
			freeExplode(_data,size);
		
		}
		
		fclose(fp);	

		fp = NULL;
	}
	
}

char *get_fileName(const char *head,const char *name,const char *tail)
{
	int len = strlen(head) + strlen(name) + strlen(tail);
	
	char *result = (char *)malloc(sizeof(char)*len);
	
	sprintf(result,"%s%s%s",head,name,tail);
	
	return result;
}

void make_data(map<Node,float> &table1, map<Node,float> &table2,map<Node,float> &table3)
{
	float a = alpha();
	
	for(map<Node,float>::iterator it_table1=table1.begin();it_table1!=table1.end();(it_table1)++)
	{
	
		float weightOne = it_table1->second;
		
		for(map<Node,float>::iterator it_table2=table2.begin();it_table2!=table2.end();(it_table2)++)
		{
				float _weight = it_table2->second;
			
				if(strcmp(it_table1->first.source,it_table2->first.source) ==0 
					&& strcmp(it_table1->first.target,it_table2->first.target)==0){
					
					weightOne = a * weightOne + (1 - a) * _weight;
						
					break;
				}
				
				Node node;
				strcpy(node.source,it_table2->first.source);
				strcpy(node.target,it_table2->first.target);					
				table3.insert(pair<Node,float>(node,_weight));
		}
		
		Node nodeOne;
		strcpy(nodeOne.source,it_table1->first.source);
		strcpy(nodeOne.source,it_table1->first.target);
		table3.insert(pair<Node,float>(nodeOne,weightOne));
		
	}
	
	for(map<Node,float>::iterator it_table2=table2.begin();it_table2!=table2.end();(it_table2)++){
		Node node;
		float _weight = it_table2->second;
		strcpy(node.source,it_table2->first.source);
		strcpy(node.target,it_table2->first.target);					
		table3.insert(pair<Node,float>(node,_weight));
	}
	
}

void write_file(const char *file_name,const map<Node,float> &table)
{
	FILE *fp;
	
	char source[10] = "Source";
	char target[10] = "Target";
	char weight[10] = "Weight";
	char end[10]    = "\n";
	
	char _weight[20];
	
	if((fp = fopen(file_name,"a+")))
	{
		fprintf(fp,"%s,",source);
		fprintf(fp,"%s,",target);
		fprintf(fp,"%s,",weight);
		fprintf(fp,"%s",end);
		
		for(map<Node,float>::const_iterator it=table.begin();it!=table.end();(it)++)
		{
			sprintf(_weight,"%f",it->second);

			fprintf(fp,"%s,",it->first.source);
			fprintf(fp,"%s,",it->first.target);
			fprintf(fp,"%s,",_weight);
			fprintf(fp,"%s",end);
		}
		
		fclose(fp);
		fp = NULL;
	}
	
}
#endif
