// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_interface.java
// Do not modify

package org.projectfloodlight.openflow.protocol.errormsg;

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

public interface OFBsnError extends OFObject, OFBsnBaseError {
    OFErrorCauseData getData();
    String getErrMsg();
    OFErrorType getErrType();
    long getExperimenter();
    int getSubtype();
    OFType getType();
    OFVersion getVersion();
    long getXid();

    void writeTo(ByteBuf channelBuffer);

    Builder createBuilder();
    public interface Builder extends OFBsnBaseError.Builder {
        OFBsnError build();
        OFErrorCauseData getData();
        Builder setData(OFErrorCauseData data);
        String getErrMsg();
        Builder setErrMsg(String errMsg);
        OFErrorType getErrType();
        long getExperimenter();
        int getSubtype();
        Builder setSubtype(int subtype);
        OFType getType();
        OFVersion getVersion();
        long getXid();
        Builder setXid(long xid);
    }
}
