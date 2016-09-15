#pragma once
/********************************************************************
 FileName: ThinkOflEinstein.h
 Description: ����˹̹��˼����
				
 Author: wangpengjun
 Created: 2016/9/15 12:23
*********************************************************************/

//��ʾ���Ե�����
enum ITEM_TYPE
{
	color, nationality,drink,pet, cigarette
};


//���Ե����ݽṹ����
typedef struct tagItem
{
	ITEM_TYPE type;
	int value;
}ITEM;

#define GROUPS_ITEMS 5
typedef struct tagGroup
{
	ITEM items[GROUPS_ITEMS];
}GROUP;
//ÿ�η��ʶ�Ҫ����items���ҵ����ʵ�����

//�Ľ�->ÿ���������Ŀ�����Ͷ��ǹ̶��ģ�ʹ��һ��ά��
struct tagGroup2
{
	int itemValue[GROUPS_ITEMS];
}GROUP2;

typedef enum tagItemType
{
	type_house = 0,
	type_nation = 1,
	type_drink = 2,
	type_pet = 3,
	type_cigaret = 4
}ITEM_TYPE;

//  if(group.itemValue[type_house]==COLOR_BLUE)

/****************************************************************************************************/
//����Ϊ����ģ�Ͷ���  ����Ϊ����ģ��  �ж�һ��ö�ٽ���Ƿ���ȷ
//��һ�� ���а󶨹�ϵ��ģ��  �絤���˺Ȳ�
struct  tagBind
{
	ITEM_TYPE first_type;
	int first_val;
	ITEM_TYPE second_type;
	int second_val;
};
/*����֪����д��
const BIND binds[] =
{
	{ type_house, COLOR_RED, type_nation, NATION_ENGLAND },
	{ type_nation, NATION_SWEDEND, type_pet, PET_DOG },
	{ type_nation, NATION_DANMARK, type_drink, DRINK_TEA },
	{ type_house, COLOR_GREEN, type_drink, DRINK_COFFEE },
	{ type_cigaret, CIGARET_PALLMALL, type_pet, PET_BIRD },
	{ type_house, COLOR_YELLOW, type_cigaret, CIGARET_DUNHILL },
	{ type_cigaret, CIGARET_BLUEMASTER, type_drink, DRINK_BEER },
	{ type_nation, NATION_GERMANY, type_cigaret, CIGARET_PRINCE }
};
*/

//�ڶ���Ԫ��  ���ڹ�ϵ ��������˺ͳ�Dunhill���̵�������
struct tagRelation
{
	ITEM_TYPE type;
	int val;
	ITEM_TYPE relation_type;
	int relation_val;
}RELATION;

//������ �޷�ͳһ������ѧģ�͡�ֱ���ж�

/*******************************************************************************************************/
//�㷨ʵ��

/*
static int cnt = 0;
void DoGroupsfinalCheck(GROUP *groups)
{
cnt++;
if((cnt % 1000000) == 0)
printf("%d\n", cnt);

if(CheckAllGroupsBind(groups, binds) && CheckAllGroupsRelation(groups, relations))
{
PrintAllGroupsResult(groups, GROUPS_COUNT);
}
}
*/

/* ����������ɫ
void EnumHouseColors(GROUP *groups, int groupIdx)
{
	if (groupIdx == GROUPS_COUNT) 
	{
		ArrangeHouseNations(groups);
		return;
	}

	for (int i = COLOR_BLUE; i <= COLOR_YELLOW; i++)
	{
		if (!IsGroupItemValueUsed(groups, groupIdx, type_house, i))
		{
			groups[groupIdx].itemValue[type_house] = i;
			if (i == COLOR_GREEN) //Ӧ������(4)���̷��ӽ����Ű׷��ӣ��ڰ׷��ӵ���ߣ�
			{
				groups[++groupIdx].itemValue[type_house] = COLOR_WHITE;
			}

			EnumHouseColors(groups, groupIdx + 1);
			if (i == COLOR_GREEN)
			{
				groupIdx--;
			}
		}
	}
}
*/


/*
void EnumPeopleCigerts(GROUP *groups, int groupIdx)
{
if(groupIdx == GROUPS_COUNT) 
{
	DoGroupsfinalCheck(groups);
	return;
}

for (int i = CIGARET_BLENDS; i <= CIGARET_BLUEMASTER; i++)
{
	if (!IsGroupItemValueUsed(groups, groupIdx, type_cigaret, i))
	{
		groups[groupIdx].itemValue[type_cigaret] = i;

		EnumPeopleCigerts(groups, groupIdx + 1);
	}
}
}

*/

/*
int main(int argc, char* argv[])
{
	GROUP groups[GROUPS_COUNT] = { { 0 } };

	EnumHouseColors(groups, 0);

	return 0;
}
*/
//�ܽ᣺
/*
1.��������ģ��  int ��������ʾһ���״��  const int ĳһ�����磺��ɫ ��ɫ��
2.��������ģ�� �������������  Ȼ�����������������������޷���������  ������ڱ����� �����ж�
3.�ݹ� �����������
4.�ݹ�Ľ������������ж�
if (groupIdx == GROUPS_COUNT)
	{
		ArrangeHouseNations(groups);
		return;
	}
4.ע�����
�������ӵĵݹ���
if(i == COLOR_GREEN) //Ӧ������(4)���̷��ӽ����Ű׷��ӣ��ڰ׷��ӵ���ߣ�
{
groups[++groupIdx].itemValue[type_house] = COLOR_WHITE;
}

EnumHouseColors(groups, groupIdx + 1);
if(i == COLOR_GREEN)
{
groupIdx--;
}

���ָ��ֳ�����Ϊ�������´�ѭ��������ʱ�÷��Ӳ�����ɫ��������Ҫȡ���ϴεļ��衣
���ݹ�����Ϊ����������������⴦����ݹ��Ҫ���лظ���

*/
