#define foreach(tab,it) for(decltype(tab)::iterator it=(tab).begin(); it!=(tab).end(); it++)
#define foreachs(kind,tab,it) for(decltype(tab)::kind##_iterator it=(tab).begin(); it!=(tab).end(); it++)
