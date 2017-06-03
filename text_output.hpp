#include <fstream>
#include <shlobj.h>
#include <string>


enum 
{
  DESKTOP
};

#ifndef __TEXTOUTPRINT_H_
#define __TEXTOUTPRINT_H_



class TextOutput{
public:

	//コンストラクタ
	TextOutput();
	//デストラクタ
	~TextOutput();

	//引数:(タイトル,本文)
	void WriteText(std::string,std::string);
	//引数:(タイトル,本文,パス)
	void WriteText(std::string, std::string , int);

private:

	//デスクトップのパスを取得
	std::string getDeskPath();
	//拡張子が指定されていなければ追加
	std::string addExtension(std::string);

};
#endif