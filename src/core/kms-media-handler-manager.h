#if !defined (__KMS_CORE_H_INSIDE__)
#error "Only <kms-core.h> can be included directly."
#endif

#ifndef __KMS_MEDIA_HANDLER_MANAGER_H__
#define __KMS_MEDIA_HANDLER_MANAGER_H__

#include <glib-object.h>
#include "kms-media-handler-factory.h"

#define KMS_TYPE_MEDIA_HANDLER_MANAGER			(kms_media_handler_manager_get_type())
#define KMS_MEDIA_HANDLER_MANAGER(obj)			(G_TYPE_CHECK_INSTANCE_CAST((obj), KMS_TYPE_MEDIA_HANDLER_MANAGER, KmsMediaHandlerManager))
#define KMS_IS_MEDIA_HANDLER_MANAGER(obj)		(G_TYPE_CHECK_INSTANCE_TYPE((obj), KMS_TYPE_MEDIA_HANDLER_MANAGER))
#define KMS_MEDIA_HANDLER_MANAGER_GET_INTERFACE(inst)	(G_TYPE_INSTANCE_GET_INTERFACE((inst), KMS_TYPE_MEDIA_HANDLER_MANAGER, KmsMediaHandlerManagerInterface))

typedef struct _KmsMediaHandlerManager		KmsMediaHandlerManager; /* dummy object */
typedef struct _KmsMediaHandlerManagerInterface	KmsMediaHandlerManagerInterface;

struct _KmsMediaHandlerManagerInterface
{
	GTypeInterface parent_iface;

	/* Virtual methods */
	KmsMediaHandlerFactory *(*get_factory)(KmsMediaHandlerManager *self);
	void (*dispose_factory)(KmsMediaHandlerManager *self,
					KmsMediaHandlerFactory *factory);
};

GType kms_media_handler_manager_get_type(void);

KmsMediaHandlerFactory*
kms_media_handler_manager_get_factory(KmsMediaHandlerManager *self);

void kms_media_handler_manager_dispose_factory(KmsMediaHandlerManager *self,
					KmsMediaHandlerFactory *factory);

#endif /* __KMS_MEDIA_HANDLER_MANAGER_H__ */
