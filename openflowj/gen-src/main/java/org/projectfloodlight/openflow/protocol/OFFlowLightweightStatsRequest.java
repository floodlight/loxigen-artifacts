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
import java.util.Set;
import io.netty.buffer.ByteBuf;

public interface OFFlowLightweightStatsRequest extends OFObject, OFStatsRequest<OFFlowLightweightStatsReply>, OFRequest<OFFlowLightweightStatsReply> {
    U64 getCookie();
    U64 getCookieMask();
    Set<OFStatsRequestFlags> getFlags();
    Match getMatch();
    OFGroup getOutGroup();
    OFPort getOutPort();
    OFStatsType getStatsType();
    TableId getTableId();
    OFType getType();
    OFVersion getVersion();
    long getXid();

    void writeTo(ByteBuf channelBuffer);

    Builder createBuilder();
    public interface Builder extends OFStatsRequest.Builder<OFFlowLightweightStatsReply> {
        OFFlowLightweightStatsRequest build();
        U64 getCookie();
        Builder setCookie(U64 cookie);
        U64 getCookieMask();
        Builder setCookieMask(U64 cookieMask);
        Set<OFStatsRequestFlags> getFlags();
        Builder setFlags(Set<OFStatsRequestFlags> flags);
        Match getMatch();
        Builder setMatch(Match match);
        OFGroup getOutGroup();
        Builder setOutGroup(OFGroup outGroup);
        OFPort getOutPort();
        Builder setOutPort(OFPort outPort);
        OFStatsType getStatsType();
        TableId getTableId();
        Builder setTableId(TableId tableId);
        OFType getType();
        OFVersion getVersion();
        long getXid();
        Builder setXid(long xid);
    }
}
