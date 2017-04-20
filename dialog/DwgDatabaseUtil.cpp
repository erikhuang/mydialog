
#include "StdAfx.h"
#include "DwgDatabaseUtil.h"

CDwgDatabaseUtil::CDwgDatabaseUtil()
{

}

CDwgDatabaseUtil::~CDwgDatabaseUtil()
{

}

AcDbObjectId CDwgDatabaseUtil::PostToModalSpace(AcDbEntity* pEnt)
{
	ASSERT(pEnt);

	Acad::ErrorStatus es;
	AcDbBlockTable* pBlockTable=NULL;
	AcDbObjectId entId=AcDbObjectId::kNull;
	es=acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForNotify);
	if (es==Acad::eOk)
	{
		AcDbBlockTableRecord* pBlockTableRecord=NULL;
		es=pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
		pBlockTable->close();

		if (es==Acad::eOk)
		{
			es=pBlockTableRecord->appendAcDbEntity(entId, pEnt);
			pBlockTableRecord->close();

			if (es==Acad::eOk)
			{
				pEnt->close();
			}
			else
			{
				entId=AcDbObjectId::kNull;
			}
		}
	}
	return entId;
}