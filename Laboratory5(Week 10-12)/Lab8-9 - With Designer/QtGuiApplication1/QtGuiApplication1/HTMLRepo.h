#pragma once
#include "IFileRepository.h"

class HTMLRepository : public IFileRepository {
protected:
	void repoFromFile() override;
	void repoToFile() override;
	
public:
	std::string site;
	HTMLRepository(const std::string& source,const std::string& site);
	~HTMLRepository();
	void display() override;
};