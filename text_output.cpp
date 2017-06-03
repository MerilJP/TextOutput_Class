#include "text_output.hpp"

TextOutput::TextOutput()
{
}

TextOutput::~TextOutput()
{
}

//引数:(タイトル,本文)
void TextOutput::WriteText(std::string Title, std::string TextMain)
{
	std::ofstream ofs;

	//拡張子が指定されていなければ追加
	this->addExtension(Title);
	//出力ファイル名
	ofs.open(Title, std::ios::out);
	//ファイルを出力
	ofs << TextMain << std::endl;
	//後処理
	ofs.close();
}

//引数:(タイトル,本文,パス)
void TextOutput::WriteText(std::string Title, std::string TextMain, int Path)
{
	std::ofstream ofs;
	
	//拡張子が指定されていなければ追加
	this->addExtension(Title);

	//出力パス
	switch (Path)
	{
	case DESKTOP:
		ofs.open(this->getDeskPath() + Title, std::ios::out);
		break;
	default:
		ofs.open(this->getDeskPath() + Title, std::ios::out);
		break;
	}	
	//ファイルを出力
	ofs << TextMain << std::endl;
	//後処理
	ofs.close();
}

//デスクトップパスを取得
std::string TextOutput::getDeskPath()
{
	std::wstring wsBuf;
	TCHAR szPath[MAX_PATH];

	SHGetSpecialFolderPath(NULL, szPath, CSIDL_DESKTOP, false);
	wsBuf = szPath;
	
	std::string stBuf(wsBuf.begin(),wsBuf.end());
	for (int i = 0; i <= (int)stBuf.length(); i++) 
	{
		if (stBuf[i] == '\\')
		{
			stBuf.insert(stBuf.begin() + i, '\\');
			i++;
		}
	}
	stBuf = stBuf + "\\\\";

	return stBuf;
}

//ファイル拡張子の追加
void TextOutput::addExtension(std::string Title)
{
	//拡張子が設定されていなければ末尾に追加する
	std::string::size_type ret = Title.find(".txt");
	if (ret == std::string::npos)
	{
		Title = Title + ".txt";
	}
}
