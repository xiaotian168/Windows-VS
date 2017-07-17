#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct dict
{
	char *key;
	char *content;
	struct dict *next;	//����һ��nextָ����
};

void format_string(char *str)//ȥ���ַ�����β�Ļس����ո��ַ�
{
	size_t i;
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r')
		{
			str[i + 1] = '\0';
			break;
		}
	}
}

//���ֵ��ļ�������ȡ�ļ�����
int open_dict(struct dict **p, const char *dict_filename)
{
	FILE *pfile = fopen(dict_filename, "r");
	if (pfile == NULL)
		return 0;//���ļ�ʧ�ܣ���������

				 //����һ��ͷ���
	struct dict * head = (struct dict *)calloc(1, sizeof(struct dict)); //struct dict *ָ��struct dict
	if (head == NULL)
	{
		return 0;
	}

	*p = head; //��Ӹ�ֵ

	struct dict *tmp = NULL; //�½ڵ�
	struct dict *cur = NULL; //β�ڵ�
	cur = head;


	char buf[2048] = { 0 };
	size_t len = 0;
	int i = 0;//������
	while (!feof(pfile))//ѭ����ȡ�ļ���ֱ���ļ�ĩβ
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);//��ȡ�ļ�һ��
		len = strlen(buf);//�õ���ȡ���ַ�������
		if (len > 0)
		{
			//�����ݣ���Ҫ�½ڵ�
			tmp = (struct dict *)calloc(1, sizeof(struct dict));

			//���浥��
			tmp->key = (char *)calloc(1, len);//�����ַ������ȷ����ڴ�

			format_string(buf);//ȥ���ַ�����β�Ŀո�ͻس�
			strcpy(tmp->key, &buf[1]);//����ȡ�������ݿ�����key��
		}

		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);
		len = strlen(buf);
		if (len > 0)
		{
			//�½ڵ㣬���浥�ʵĽ���
			tmp->content = (char *)calloc(1, len);
			strcpy(tmp->content, &buf[6]);

			//�ڵ㽨����ϵ
			cur->next = tmp;
			tmp->next = NULL; //��Ϊβ���
			cur = tmp; //����β���
		}

		i++;//��������1
	}
	fclose(pfile);//�ر��ֵ��ļ�

	return i;//���ض�ȡ�����ֵ������
}

//���ݹؼ���key,���ֵ��в�������
int search_dict(const struct dict *p, int size, const char *key, char *content)
{
	if (p == NULL)
	{
		return 0;
	}

	const struct dict * tmp = p->next;
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			strcpy(content, tmp->content);
			return 1;//�ҵ�����������¼������1
		}

		//ָ�������ƶ�
		tmp = tmp->next;
	}

	return 0;//û���ҵ�����������¼������0
}

//�ͷ��ڴ�
void free_dict(struct dict *p, int size)
{
	if (p == NULL)
	{
		return;
	}

	struct dict *del = p;
	struct dict *tmp = p;
	while (tmp != NULL)
	{
		//�ͷŵ�ǰ�ڵ�ǰ���ȱ�����һ���ڵ�
		tmp = tmp->next;

		//���ͷų�Ա
		if (del->key != NULL)
		{
			free(del->key);
			del->key = NULL;
		}
		if (del->content != NULL)
		{
			free(del->content);
			del->content = NULL;
		}

		//���ͷŽṹ�屾��
		free(del);

		del = tmp; //������һ���ڵ�
	}

}


int main(int argc, char *args[])
{

	long start_ms = 0;//��¼����ִ�еĿ�ʼʱ��
	long end_ms = 0;//��¼����ִ�еĽ���ʱ��
	struct dict *p = NULL; //p���������ͷ���
	start_ms = clock();
	int dict_size = open_dict(&p, "./dict_gbk.txt");//���������е�һ��������Ϊ�ֵ��ļ��������ֵ��ļ�
	if (dict_size == 0)
	{
		fprintf(stdout, "���Ӵʵ��ʧ��\n");
		system("pause");
		return 0;//���ֵ��ļ�ʧ�ܣ������˳�
	}
		

	end_ms = clock();
	printf("���سɹ�����ʱ: %ld ms\n\t\t����xiaotian�˳�����\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������

	char key[1024];
	char content[1024];
	while (1)
	{
		memset(key, 0, sizeof(key));
		memset(content, 0, sizeof(content));
		fgets(key, sizeof(key), stdin);//�Ӽ��̵õ��û�����
		format_string(key);//ȥ���ַ�����β�Ŀո�ͻس�
		if (strncmp(key, "xiaotian", 8) == 0)
			break;

		start_ms = clock();
		if (search_dict(p, dict_size, key, content))//�����û����룬���ֵ��м���
		{
			printf("%s", content);
		}
		else
		{
			printf("û�дε���\n");
			continue;
		}
		end_ms = clock();
		printf("���Һ�ʱ: %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������
	}

	start_ms = clock();
	free_dict(p, dict_size);
	end_ms = clock();
	printf("�ͷſռ��ʱ: %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������
	system("pause");
	return 0;
}
