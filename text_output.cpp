#include "text_output.hpp"

TextOutput::TextOutput()
{
}

TextOutput::~TextOutput()
{
}

//����:(�^�C�g��,�{��)
void TextOutput::WriteText(std::string Title, std::string TextMain)
{
	std::ofstream ofs;

	//�g���q���w�肳��Ă��Ȃ���Βǉ�
	this->addExtension(Title);
	//�o�̓t�@�C����
	ofs.open(Title, std::ios::out);
	//�t�@�C�����o��
	ofs << TextMain << std::endl;
	//�㏈��
	ofs.close();
}

//����:(�^�C�g��,�{��,�p�X)
void TextOutput::WriteText(std::string Title, std::string TextMain, int Path)
{
	std::ofstream ofs;
	
	//�g���q���w�肳��Ă��Ȃ���Βǉ�
	this->addExtension(Title);

	//�o�̓p�X
	switch (Path)
	{
	case DESKTOP:
		ofs.open(this->getDeskPath() + Title, std::ios::out);
		break;
	default:
		ofs.open(this->getDeskPath() + Title, std::ios::out);
		break;
	}	
	//�t�@�C�����o��
	ofs << TextMain << std::endl;
	//�㏈��
	ofs.close();
}

//�f�X�N�g�b�v�p�X���擾
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

//�t�@�C���g���q�̒ǉ�
void TextOutput::addExtension(std::string Title)
{
	//�g���q���ݒ肳��Ă��Ȃ���Ζ����ɒǉ�����
	std::string::size_type ret = Title.find(".txt");
	if (ret == std::string::npos)
	{
		Title = Title + ".txt";
	}
}
