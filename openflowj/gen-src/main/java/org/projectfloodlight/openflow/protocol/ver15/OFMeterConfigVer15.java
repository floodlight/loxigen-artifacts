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
import com.google.common.collect.ImmutableSet;
import java.util.List;
import com.google.common.collect.ImmutableList;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFMeterConfigVer15 implements OFMeterConfig {
    private static final Logger logger = LoggerFactory.getLogger(OFMeterConfigVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 8;

        private final static Set<OFMeterFlags> DEFAULT_FLAGS = ImmutableSet.<OFMeterFlags>of();
        private final static long DEFAULT_METER_ID = 0x0L;
        private final static List<OFMeterBand> DEFAULT_ENTRIES = ImmutableList.<OFMeterBand>of();

    // OF message fields
    private final Set<OFMeterFlags> flags;
    private final long meterId;
    private final List<OFMeterBand> entries;
//
    // Immutable default instance
    final static OFMeterConfigVer15 DEFAULT = new OFMeterConfigVer15(
        DEFAULT_FLAGS, DEFAULT_METER_ID, DEFAULT_ENTRIES
    );

    // package private constructor - used by readers, builders, and factory
    OFMeterConfigVer15(Set<OFMeterFlags> flags, long meterId, List<OFMeterBand> entries) {
        if(flags == null) {
            throw new NullPointerException("OFMeterConfigVer15: property flags cannot be null");
        }
        if(entries == null) {
            throw new NullPointerException("OFMeterConfigVer15: property entries cannot be null");
        }
        this.flags = flags;
        this.meterId = meterId;
        this.entries = entries;
    }

    // Accessors for OF message fields
    @Override
    public Set<OFMeterFlags> getFlags() {
        return flags;
    }

    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public List<OFMeterBand> getEntries() {
        return entries;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFMeterConfig.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFMeterConfig.Builder {
        final OFMeterConfigVer15 parentMessage;

        // OF message fields
        private boolean flagsSet;
        private Set<OFMeterFlags> flags;
        private boolean meterIdSet;
        private long meterId;
        private boolean entriesSet;
        private List<OFMeterBand> entries;

        BuilderWithParent(OFMeterConfigVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public Set<OFMeterFlags> getFlags() {
        return flags;
    }

    @Override
    public OFMeterConfig.Builder setFlags(Set<OFMeterFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFMeterConfig.Builder setMeterId(long meterId) {
        this.meterId = meterId;
        this.meterIdSet = true;
        return this;
    }
    @Override
    public List<OFMeterBand> getEntries() {
        return entries;
    }

    @Override
    public OFMeterConfig.Builder setEntries(List<OFMeterBand> entries) {
        this.entries = entries;
        this.entriesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFMeterConfig build() {
                Set<OFMeterFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                long meterId = this.meterIdSet ? this.meterId : parentMessage.meterId;
                List<OFMeterBand> entries = this.entriesSet ? this.entries : parentMessage.entries;
                if(entries == null)
                    throw new NullPointerException("Property entries must not be null");

                //
                return new OFMeterConfigVer15(
                    flags,
                    meterId,
                    entries
                );
        }

    }

    static class Builder implements OFMeterConfig.Builder {
        // OF message fields
        private boolean flagsSet;
        private Set<OFMeterFlags> flags;
        private boolean meterIdSet;
        private long meterId;
        private boolean entriesSet;
        private List<OFMeterBand> entries;

    @Override
    public Set<OFMeterFlags> getFlags() {
        return flags;
    }

    @Override
    public OFMeterConfig.Builder setFlags(Set<OFMeterFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFMeterConfig.Builder setMeterId(long meterId) {
        this.meterId = meterId;
        this.meterIdSet = true;
        return this;
    }
    @Override
    public List<OFMeterBand> getEntries() {
        return entries;
    }

    @Override
    public OFMeterConfig.Builder setEntries(List<OFMeterBand> entries) {
        this.entries = entries;
        this.entriesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFMeterConfig build() {
            Set<OFMeterFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            long meterId = this.meterIdSet ? this.meterId : DEFAULT_METER_ID;
            List<OFMeterBand> entries = this.entriesSet ? this.entries : DEFAULT_ENTRIES;
            if(entries == null)
                throw new NullPointerException("Property entries must not be null");


            return new OFMeterConfigVer15(
                    flags,
                    meterId,
                    entries
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFMeterConfig> {
        @Override
        public OFMeterConfig readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            //
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            Set<OFMeterFlags> flags = OFMeterFlagsSerializerVer15.readFrom(bb);
            long meterId = U32.f(bb.readInt());
            List<OFMeterBand> entries = ChannelUtils.readList(context, bb, length - (bb.readerIndex() - start), OFMeterBandVer15.READER);

            OFMeterConfigVer15 meterConfigVer15 = new OFMeterConfigVer15(
                    flags,
                      meterId,
                      entries
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", meterConfigVer15);
            return meterConfigVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFMeterConfigVer15Funnel FUNNEL = new OFMeterConfigVer15Funnel();
    static class OFMeterConfigVer15Funnel implements Funnel<OFMeterConfigVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFMeterConfigVer15 message, PrimitiveSink sink) {
            // FIXME: skip funnel of length
            OFMeterFlagsSerializerVer15.putTo(message.flags, sink);
            sink.putLong(message.meterId);
            FunnelUtils.putList(message.entries, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFMeterConfigVer15> {
        @Override
        public void write(ByteBuf bb, OFMeterConfigVer15 message) {
            int startIndex = bb.writerIndex();
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            OFMeterFlagsSerializerVer15.writeTo(bb, message.flags);
            bb.writeInt(U32.t(message.meterId));
            ChannelUtils.writeList(bb, message.entries);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFMeterConfigVer15(");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("meterId=").append(meterId);
        b.append(", ");
        b.append("entries=").append(entries);
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
        OFMeterConfigVer15 other = (OFMeterConfigVer15) obj;

        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if( meterId != other.meterId)
            return false;
        if (entries == null) {
            if (other.entries != null)
                return false;
        } else if (!entries.equals(other.entries))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime *  (int) (meterId ^ (meterId >>> 32));
        result = prime * result + ((entries == null) ? 0 : entries.hashCode());
        return result;
    }

}
