#pragma once



//表示属性的类型
enum ITEM_TYPE
{
	color, nationality,drink,pet, cigarette
};


//属性的数据结构定义
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
//每次访问都要遍历items，找到合适的类型

//改进->每组的属性数目及类型都是固定的，使用一个维度
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
//以上为基本模型定义  下面为线索模型  判断一个枚举结果是否正确
//第一类 具有绑定关系的模型  如丹麦人喝茶
struct  tagBind
{
	ITEM_TYPE first_type;
	int first_val;
	ITEM_TYPE second_type;
	int second_val;
};
/*将已知条件写入
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

//第二类元素  相邻关系 如养马的人和抽Dunhill香烟的人相邻
struct tagRelation
{
	ITEM_TYPE type;
	int val;
	ITEM_TYPE relation_type;
	int relation_val;
}RELATION;

//第三类 无法统一建立数学模型。直接判断

/*******************************************************************************************************/
//算法实现
