#pragma once
/********************************************************************
 FileName: ThinkOflEinstein.h
 Description: 爱因斯坦的思考题
				
 Author: wangpengjun
 Created: 2016/9/15 12:23
*********************************************************************/

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

/* 遍历房子颜色
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
			if (i == COLOR_GREEN) //应用线索(4)：绿房子紧挨着白房子，在白房子的左边；
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
//总结：
/*
1.建立基本模型  int 数组来表示一组的状况  const int 某一属性如：白色 黄色等
2.建立线索模型 这个分析了条件  然后建立了两种线索，第三种无法建立线索  则放置在遍历中 无需判断
3.递归 穷举所有种类
4.递归的结束条件用来判断
if (groupIdx == GROUPS_COUNT)
	{
		ArrangeHouseNations(groups);
		return;
	}
4.注意事项：
遍历房子的递归中
if(i == COLOR_GREEN) //应用线索(4)：绿房子紧挨着白房子，在白房子的左边；
{
groups[++groupIdx].itemValue[type_house] = COLOR_WHITE;
}

EnumHouseColors(groups, groupIdx + 1);
if(i == COLOR_GREEN)
{
groupIdx--;
}

最后恢复现场，因为还会有下次循环，而此时该房子不是绿色，所以需要取消上次的假设。
若递归中因为特殊情况进行了特殊处理，则递归后要进行回复。

*/
