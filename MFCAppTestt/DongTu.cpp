#include "pch.h"
#include "DongTu.h"
#include <stdlib.h>
using namespace std;
CString chuyendoiV2(CString tu, CString doi) {
    CString temp = tu;
    temp.Replace(L"る", doi);
    return temp;
}
DongTu::DongTu(CString* mang)
{
    if (mang) {
        this->voc = mang[3];
        this->type_voc = mang[2];
    }
    
}
CString chuyendoiV3(CString tu,CString tucuoi, CString doi) {
    CString temp = tu;
    temp.Replace(tucuoi, doi);
    return temp;
}
CString* DongTu::chiadongtu()
{
    CString* list_dong_tu = new CString[7];
    list_dong_tu[0] = this->voc;

    int tl = _ttoi(this->type_voc);
    switch (tl){
    case 1: {
        CString** the = new CString * [7];
        the[0] = new CString[]{ L"う", L"く", L"す", L"つ", L"ぬ", L"ふ", L"む", L"る", L"ぐ", L"ぶ" };
        the[1] = new CString[]{ L"います", L"きます", L"します", L"ちます", L"Ｘ", L"X", L"みます", L"ります", L"ぎます", L"びます" };
        the[2] = new CString[]{ L"って", L"って", L"して", L"って", L"Ｘ", L"Ｘ", L"んで", L"って", L"いで", L"んで" };
        the[3] = new CString[]{ L"おう", L"こう", L"そう", L"とう", L"Ｘ", L"Ｘ", L"もう", L"ろう", L"ごう", L"ぼう" };
        the[4] = new CString[]{ L"える", L"ける", L"せる", L"てる", L"Ｘ", L"Ｘ", L"める", L"れる", L"げる", L"べる" };
        the[5] = new CString[]{ L"えば", L"けば", L"せば", L"てば", L"Ｘ", L"Ｘ", L"めば", L"れば", L"げば", L"べば" };
        the[6] = new CString[]{ L"わない", L"かない", L"さない", L"たない", L"X", L"X", L"まない", L"らない", L"がない", L"ばない" };
        CString tu_nguyen_mau{ this->voc.GetAt(this->voc.GetLength() - 1) };
        for (size_t j = 0; j < 10; j++)
        {
            if (the[0][j]==tu_nguyen_mau)
            {
                for (size_t i = 1; i < 7; i++)
                {
                    CString temp = this->voc;
                    temp.Replace(the[0][j],the[i][j]);
                    list_dong_tu[i] = temp;
                }
                return list_dong_tu;
            }
        }
    }break;
    case 2: {

        CString tu_nguyen_mau{ this->voc.GetAt(this->voc.GetLength() - 1) };
  
        CString dsV[] = {L"ます", L"て", L"よう", L"られる", L"れば" , L"ない" };
        for (size_t i = 1; i < 7; i++)
        {
            list_dong_tu[i] = chuyendoiV2(this->voc, dsV[i-1]);
        }
    }break;
    default: {
        CString tu_cuoi{ this->voc.GetAt(this->voc.GetLength() - 2) };
        CString tu_nguyen_mau{ this->voc.GetAt(this->voc.GetLength() - 1) };
        CString tu = tu_cuoi + tu_nguyen_mau;

        if (tu==L"する")
        {
            CString dsV[] = { L"します", L"して", L"しよう", L"できる", L"すれば" , L"しない" };
            for (size_t i = 1; i < 7; i++)
            {
                list_dong_tu[i] = chuyendoiV3(this->voc, L"する", dsV[i - 1]);
            }
        }
        else
        {
            CString dsV[] = { L"ます", L"て", L"よう", L"られる", L"れば" , L"ない" };
            for (size_t i = 1; i < 7; i++)
            {
                list_dong_tu[i] = chuyendoiV3(this->voc, L"る", dsV[i - 1]);
            }
        }
    }
        break;
    }
    return list_dong_tu;
}

DongTu::~DongTu()
{
}
