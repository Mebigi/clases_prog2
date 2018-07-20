

struct S_Service
{
 int id;
 char name[33];
 char email[65];
};
typedef struct S_Service Service;


char* serv_get_name(Service*);
