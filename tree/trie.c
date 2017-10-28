#include<stdio.h>
#include<stdlib.h>

struct trie{
struct trie *children[26];
int isleaf;
};

struct trie *create()
{
    int i;
    struct trie *p=(struct trie *)malloc(sizeof(struct trie));
    for(i=0;i<26;i++)
    {
        p->children[i]=NULL;
    }
    p->isleaf=0;
    return p;
};

void insert(struct trie *root,char *key)
{
int level;
int length=strlen(key);
struct trie *p=root;
for(level=0;level<length;level++)
{
    int index=key[level]-'a';
    if(p->children[index]==NULL)
    {
        p->children[index]=create();
    }
    p=p->children[index];
}
p->isleaf=1;
}

void display(struct trie* root, char str[], int level)
{
if (root->isleaf==1)
    {
        str[level] = '\0';
        printf("%s\n",str);
    }
    int i;
    for (i = 0; i<26; i++)
    {
if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

int search(struct trie *head, char *str)
{
int i;
for(i = 0;i < strlen(str); i++)
{
if(head->children[str[i] - 'a'] == NULL)
return 0;
else
head = head -> children[str[i] - 'a'];
}
	if(head -> isleaf == 1)
		return 1;
	else
		return 0;
}

int main()
{
    int num;
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[20]; /*= {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};*/
    char output[][32] = {"Not present in trie", "Present in trie"};
    struct trie *root = create();
    while(1)
    {
        printf("\n1.insert\n2.search\n3.display\n");
        scanf("%d",&num);
        if(num==1)
        {
            printf("enter the  word to insert\n");
            scanf("%s",keys);
            insert(root,keys);
        }
        else if(num==2)
        {
            printf("enter the word to search\n");
            scanf("%s",keys);
            printf("%s is %s\n", keys, output[search(root, keys)] );
        }
        /*else if(num==3)
        {
            display();
        }*/
        else
            break;
    }


    return 0;
}
