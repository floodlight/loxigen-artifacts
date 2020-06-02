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
import java.util.List;
import com.google.common.collect.ImmutableList;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFTableFeaturePropNextTablesMissVer15 implements OFTableFeaturePropNextTablesMiss {
    private static final Logger logger = LoggerFactory.getLogger(OFTableFeaturePropNextTablesMissVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 4;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static List<U8> DEFAULT_NEXT_TABLE_IDS = ImmutableList.<U8>of();

    // OF message fields
    private final List<U8> nextTableIds;
//
    // Immutable default instance
    final static OFTableFeaturePropNextTablesMissVer15 DEFAULT = new OFTableFeaturePropNextTablesMissVer15(
        DEFAULT_NEXT_TABLE_IDS
    );

    // package private constructor - used by readers, builders, and factory
    OFTableFeaturePropNextTablesMissVer15(List<U8> nextTableIds) {
        if(nextTableIds == null) {
            throw new NullPointerException("OFTableFeaturePropNextTablesMissVer15: property nextTableIds cannot be null");
        }
        this.nextTableIds = nextTableIds;
    }

    // Accessors for OF message fields
    @Override
    public List<U8> getNextTableIds() {
        return nextTableIds;
    }

    @Override
    public int getType() {
        return 0x3;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFTableFeaturePropNextTablesMiss.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFTableFeaturePropNextTablesMiss.Builder {
        final OFTableFeaturePropNextTablesMissVer15 parentMessage;

        // OF message fields
        private boolean nextTableIdsSet;
        private List<U8> nextTableIds;

        BuilderWithParent(OFTableFeaturePropNextTablesMissVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public List<U8> getNextTableIds() {
        return nextTableIds;
    }

    @Override
    public OFTableFeaturePropNextTablesMiss.Builder setNextTableIds(List<U8> nextTableIds) {
        this.nextTableIds = nextTableIds;
        this.nextTableIdsSet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0x3;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFTableFeaturePropNextTablesMiss build() {
                List<U8> nextTableIds = this.nextTableIdsSet ? this.nextTableIds : parentMessage.nextTableIds;
                if(nextTableIds == null)
                    throw new NullPointerException("Property nextTableIds must not be null");

                //
                return new OFTableFeaturePropNextTablesMissVer15(
                    nextTableIds
                );
        }

    }

    static class Builder implements OFTableFeaturePropNextTablesMiss.Builder {
        // OF message fields
        private boolean nextTableIdsSet;
        private List<U8> nextTableIds;

    @Override
    public List<U8> getNextTableIds() {
        return nextTableIds;
    }

    @Override
    public OFTableFeaturePropNextTablesMiss.Builder setNextTableIds(List<U8> nextTableIds) {
        this.nextTableIds = nextTableIds;
        this.nextTableIdsSet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0x3;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFTableFeaturePropNextTablesMiss build() {
            List<U8> nextTableIds = this.nextTableIdsSet ? this.nextTableIds : DEFAULT_NEXT_TABLE_IDS;
            if(nextTableIds == null)
                throw new NullPointerException("Property nextTableIds must not be null");


            return new OFTableFeaturePropNextTablesMissVer15(
                    nextTableIds
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFTableFeaturePropNextTablesMiss> {
        @Override
        public OFTableFeaturePropNextTablesMiss readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x3
            short type = bb.readShort();
            if(type != (short) 0x3)
                throw new OFParseError("Wrong type: Expected=0x3(0x3), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            List<U8> nextTableIds = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), U8.READER);

            OFTableFeaturePropNextTablesMissVer15 tableFeaturePropNextTablesMissVer15 = new OFTableFeaturePropNextTablesMissVer15(
                    nextTableIds
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", tableFeaturePropNextTablesMissVer15);
            return tableFeaturePropNextTablesMissVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFTableFeaturePropNextTablesMissVer15Funnel FUNNEL = new OFTableFeaturePropNextTablesMissVer15Funnel();
    static class OFTableFeaturePropNextTablesMissVer15Funnel implements Funnel<OFTableFeaturePropNextTablesMissVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFTableFeaturePropNextTablesMissVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0x3
            sink.putShort((short) 0x3);
            // FIXME: skip funnel of length
            FunnelUtils.putList(message.nextTableIds, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFTableFeaturePropNextTablesMissVer15> {
        @Override
        public void write(ByteBuf bb, OFTableFeaturePropNextTablesMissVer15 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 0x3
            bb.writeShort((short) 0x3);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            ChannelUtils.writeList(bb, message.nextTableIds);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFTableFeaturePropNextTablesMissVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFTableFeaturePropNextTablesMissVer15(");
        b.append("nextTableIds=").append(nextTableIds);
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
        OFTableFeaturePropNextTablesMissVer15 other = (OFTableFeaturePropNextTablesMissVer15) obj;

        if (nextTableIds == null) {
            if (other.nextTableIds != null)
                return false;
        } else if (!nextTableIds.equals(other.nextTableIds))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((nextTableIds == null) ? 0 : nextTableIds.hashCode());
        return result;
    }

}
