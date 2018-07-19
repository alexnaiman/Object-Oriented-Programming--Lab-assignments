#pragma once
#include "IFileRepository.h"

// This name for it should be JSONRepo because it writes to json that it is latter used as data for the ReactJs app
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