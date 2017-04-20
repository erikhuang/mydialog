
#ifndef _INCLUDE_CDWGDATABASEUTIL_H_
#define _INCLUDE_CDWGDATABASEUTIL_H_ 1


class CDwgDatabaseUtil
{
public:
	CDwgDatabaseUtil();
	~CDwgDatabaseUtil();

	static AcDbObjectId PostToModalSpace(AcDbEntity* pEnt);
};

#endif //_INCLUDE_CDWGDATABASEUTIL_H_