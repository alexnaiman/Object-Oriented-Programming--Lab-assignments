#pragma once
#include "IFileRepository.h"
// Repo that using the mysql cpp connector, connects to the mysql server
class SqlRepository : public IFileRepository {
protected:
	void repoFromFile() override;
	void repoToFile() override;

public:

	SqlRepository(const std::string& source);
	~SqlRepository();
	void display() override;
};