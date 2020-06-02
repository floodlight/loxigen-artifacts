// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_interface.java
// Do not modify

package org.projectfloodlight.openflow.protocol.oxm;

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

public interface OFOxmConnTrackingIpv6DstMasked extends OFObject, OFOxm<IPv6Address> {
    IPv6Address getMask();
    long getTypeLen();
    IPv6Address getValue();
    OFOxm<IPv6Address> getCanonical();
    boolean isMasked();
    MatchField<IPv6Address> getMatchField();
    OFVersion getVersion();

    void writeTo(ByteBuf channelBuffer);

    Builder createBuilder();
    public interface Builder extends OFOxm.Builder<IPv6Address> {
        OFOxmConnTrackingIpv6DstMasked build();
        IPv6Address getMask();
        Builder setMask(IPv6Address mask);
        long getTypeLen();
        IPv6Address getValue();
        Builder setValue(IPv6Address value);
        OFOxm<IPv6Address> getCanonical();
        boolean isMasked();
        MatchField<IPv6Address> getMatchField();
        OFVersion getVersion();
    }
}
