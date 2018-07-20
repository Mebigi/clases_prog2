

struct S_LogEntry
{
 char date[11];
 char time[6];
 int serviceId;
 int gravedad;
 char msg[65];

};
typedef struct S_LogEntry LogEntry;


LogEntry* loge_nuevo(void);


/** \brief setea entero en la estructura
 * \param entero a setear
 * \param Est1* puntero a estructura.
 * \return entero Ok - > 1 Error -> 0
  */ int loge_set_serviceId(LogEntry* , int );

/** \brief setea entero en la estructura
 * \param entero a setear
 * \param Est1* puntero a estructura.
 * \return entero Ok - > 1 Error -> 0
  */ int loge_set_gravedad(LogEntry* , int );
