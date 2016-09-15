#pragma once



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
