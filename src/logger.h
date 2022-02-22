#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_
enum log_level {
    debug,
    trace,
    info,
    warning,
    error
};
FILE*  log_init(char *name);
int logcat(FILE* fp, char * message, enum log_level level);
int log_close(FILE* fp);


#endif  // SRC_LOGGER_H_
