/*
 * libvirt-sandbox-console-rpc.h: libvirt sandbox rpc console
 *
 * Copyright (C) 2011-2012 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Author: Daniel P. Berrange <berrange@redhat.com>
 */

#if !defined(__LIBVIRT_SANDBOX_H__) && !defined(LIBVIRT_SANDBOX_BUILD)
#error "Only <libvirt-sandbox/libvirt-sandbox.h> can be included directly."
#endif

#ifndef __LIBVIRT_SANDBOX_CONSOLE_RPC_H__
#define __LIBVIRT_SANDBOX_CONSOLE_RPC_H__

G_BEGIN_DECLS

#define GVIR_SANDBOX_TYPE_CONSOLE_RPC            (gvir_sandbox_console_rpc_get_type ())
#define GVIR_SANDBOX_CONSOLE_RPC(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GVIR_SANDBOX_TYPE_CONSOLE_RPC, GVirSandboxConsoleRpc))
#define GVIR_SANDBOX_CONSOLE_RPC_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GVIR_SANDBOX_TYPE_CONSOLE_RPC, GVirSandboxConsoleRpcClass))
#define GVIR_SANDBOX_IS_CONSOLE_RPC(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GVIR_SANDBOX_TYPE_CONSOLE_RPC))
#define GVIR_SANDBOX_IS_CONSOLE_RPC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GVIR_SANDBOX_TYPE_CONSOLE_RPC))
#define GVIR_SANDBOX_CONSOLE_RPC_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GVIR_SANDBOX_TYPE_CONSOLE_RPC, GVirSandboxConsoleRpcClass))

typedef struct _GVirSandboxConsoleRpc GVirSandboxConsoleRpc;
typedef struct _GVirSandboxConsoleRpcPrivate GVirSandboxConsoleRpcPrivate;
typedef struct _GVirSandboxConsoleRpcClass GVirSandboxConsoleRpcClass;

struct _GVirSandboxConsoleRpc
{
    GVirSandboxConsole parent;

    GVirSandboxConsoleRpcPrivate *priv;

    /* Do not add fields to this struct */
};

struct _GVirSandboxConsoleRpcClass
{
    GVirSandboxConsoleClass parent_class;

    void (*exited)(GVirSandboxConsoleRpc *console, int status);
    void (*closed)(GVirSandboxConsoleRpc *console, gboolean err);

    gpointer padding[LIBVIRT_SANDBOX_CLASS_PADDING];
};

GType gvir_sandbox_console_rpc_get_type(void);

GVirSandboxConsoleRpc *gvir_sandbox_console_rpc_new(GVirConnection *connection,
                                                    GVirDomain *domain,
                                                    const char *devname);

G_END_DECLS

#endif /* __LIBVIRT_SANDBOX_CONSOLE_H__ */

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  indent-tabs-mode: nil
 *  tab-width: 8
 * End:
 */
