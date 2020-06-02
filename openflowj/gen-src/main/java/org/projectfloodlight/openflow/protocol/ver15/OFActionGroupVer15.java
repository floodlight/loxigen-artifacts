// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFActionGroupVer15 implements OFActionGroup {
    private static final Logger logger = LoggerFactory.getLogger(OFActionGroupVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 8;

        private final static OFGroup DEFAULT_GROUP_ID = OFGroup.ALL;

    // OF message fields
    private final OFGroup group;
//
    // Immutable default instance
    final static OFActionGroupVer15 DEFAULT = new OFActionGroupVer15(
        DEFAULT_GROUP_ID
    );

    // package private constructor - used by readers, builders, and factory
    OFActionGroupVer15(OFGroup group) {
        if(group == null) {
            throw new NullPointerException("OFActionGroupVer15: property group cannot be null");
        }
        this.group = group;
    }

    // Accessors for OF message fields
    @Override
    public OFGroup getGroup() {
        return group;
    }

    @Override
    public OFActionType getType() {
        return OFActionType.GROUP;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFActionGroup.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFActionGroup.Builder {
        final OFActionGroupVer15 parentMessage;

        // OF message fields
        private boolean groupSet;
        private OFGroup group;

        BuilderWithParent(OFActionGroupVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFGroup getGroup() {
        return group;
    }

    @Override
    public OFActionGroup.Builder setGroup(OFGroup group) {
        this.group = group;
        this.groupSet = true;
        return this;
    }
    @Override
    public OFActionType getType() {
        return OFActionType.GROUP;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFActionGroup build() {
                OFGroup group = this.groupSet ? this.group : parentMessage.group;
                if(group == null)
                    throw new NullPointerException("Property group must not be null");

                //
                return new OFActionGroupVer15(
                    group
                );
        }

    }

    static class Builder implements OFActionGroup.Builder {
        // OF message fields
        private boolean groupSet;
        private OFGroup group;

    @Override
    public OFGroup getGroup() {
        return group;
    }

    @Override
    public OFActionGroup.Builder setGroup(OFGroup group) {
        this.group = group;
        this.groupSet = true;
        return this;
    }
    @Override
    public OFActionType getType() {
        return OFActionType.GROUP;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFActionGroup build() {
            OFGroup group = this.groupSet ? this.group : DEFAULT_GROUP_ID;
            if(group == null)
                throw new NullPointerException("Property group must not be null");


            return new OFActionGroupVer15(
                    group
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFActionGroup> {
        @Override
        public OFActionGroup readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 22
            short type = bb.readShort();
            if(type != (short) 0x16)
                throw new OFParseError("Wrong type: Expected=OFActionType.GROUP(22), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 8)
                throw new OFParseError("Wrong length: Expected=8(8), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            OFGroup group = OFGroup.read4Bytes(bb);

            OFActionGroupVer15 actionGroupVer15 = new OFActionGroupVer15(
                    group
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", actionGroupVer15);
            return actionGroupVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFActionGroupVer15Funnel FUNNEL = new OFActionGroupVer15Funnel();
    static class OFActionGroupVer15Funnel implements Funnel<OFActionGroupVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFActionGroupVer15 message, PrimitiveSink sink) {
            // fixed value property type = 22
            sink.putShort((short) 0x16);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            message.group.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFActionGroupVer15> {
        @Override
        public void write(ByteBuf bb, OFActionGroupVer15 message) {
            // fixed value property type = 22
            bb.writeShort((short) 0x16);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            message.group.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFActionGroupVer15(");
        b.append("group=").append(group);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFActionGroupVer15 other = (OFActionGroupVer15) obj;

        if (group == null) {
            if (other.group != null)
                return false;
        } else if (!group.equals(other.group))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((group == null) ? 0 : group.hashCode());
        return result;
    }

}
