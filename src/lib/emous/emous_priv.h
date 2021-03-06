#define EFL_EO_API_SUPPORT
#define EFL_BETA_API_SUPPORT

#include "Emous.h"

#include <Eio.h>
#include <Ecore.h>
#include <Ecore_File.h>

extern int _log_domain;

#define CRIT(...)     EINA_LOG_DOM_CRIT(_log_domain, __VA_ARGS__)
#define ERR(...)      EINA_LOG_DOM_ERR(_log_domain, __VA_ARGS__)
#define WRN(...)      EINA_LOG_DOM_WARN(_log_domain, __VA_ARGS__)
#define INF(...)      EINA_LOG_DOM_INFO(_log_domain, __VA_ARGS__)
#define DBG(...)      EINA_LOG_DOM_DBG(_log_domain, __VA_ARGS__)

void _emous_mm_init(void);

//helperfunctions for dealing with mountpoints
void _emous_mount_point_init(void);
void _emous_mount_point_shutdown(void);

/*
 * Will add a mountpoint and emit the signal.
 * if type is known because of the initial parsing of the tree
 * this type is passed, if not a faked one is created.
 */
void _emous_mount_add(const char *type, const char *mount_point, const char *source);
/*
 * Deletes the mountpoint and emits the del event.
 * After event is done the Mount Point is freeed etc.
 */
void _emous_mount_del(const char *mount_point);

int mount_init(void);
void mount_shutdown();