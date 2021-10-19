#include "Logger.h"

int main()
{
    Logger logger("activity.log");
    logger.log("console", "login");
    logger.log("console", "watching porn");
    logger.log("console", "logoff");

    logger.log("file", "login");
    logger.log("file", "watching porn");
    logger.log("file", "logoff");

    return 0;
}