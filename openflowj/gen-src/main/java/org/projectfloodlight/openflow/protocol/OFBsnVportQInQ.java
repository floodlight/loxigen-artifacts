// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_interface.java
// Do not modify

package org.projectfloodlight.openflow.protocol;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import io.netty.buffer.ByteBuf;

public interface OFBsnVportQInQ extends OFObject, OFBsnVport {
    int getEgressTpid();
    int getEgressVlanId();
    String getIfName();
    int getIngressTpid();
    int getIngressVlanId();
    long getPortNo();
    int getType();
    OFVersion getVersion();

    void writeTo(ByteBuf channelBuffer);

    Builder createBuilder();
    public interface Builder extends OFBsnVport.Builder {
        OFBsnVportQInQ build();
        int getEgressTpid();
        Builder setEgressTpid(int egressTpid);
        int getEgressVlanId();
        Builder setEgressVlanId(int egressVlanId);
        String getIfName();
        Builder setIfName(String ifName);
        int getIngressTpid();
        Builder setIngressTpid(int ingressTpid);
        int getIngressVlanId();
        Builder setIngressVlanId(int ingressVlanId);
        long getPortNo();
        Builder setPortNo(long portNo);
        int getType();
        OFVersion getVersion();
    }
}
