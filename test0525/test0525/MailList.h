#ifndef _MAILLIST_H
#define _MAILLIST_H

typedef struct MailList
{
	char ����[50];
	char �Ա�;
	char �绰[20];
	char סַ[100];
	int ����;
	MailList *next;
}MailList[1000], *List;

enum {
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMTTY_MSG
};
#endif /*_MAILLIST_H*/