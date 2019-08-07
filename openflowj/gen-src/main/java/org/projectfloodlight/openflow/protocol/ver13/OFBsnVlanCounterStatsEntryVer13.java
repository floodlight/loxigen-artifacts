// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

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

class OFBsnVlanCounterStatsEntryVer13 implements OFBsnVlanCounterStatsEntry {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnVlanCounterStatsEntryVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int MINIMUM_LENGTH = 8;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static int DEFAULT_VLAN_VID = 0x0;
        private final static List<U64> DEFAULT_VALUES = ImmutableList.<U64>of();

    // OF message fields
    private final int vlanVid;
    private final List<U64> values;
//
    // Immutable default instance
    final static OFBsnVlanCounterStatsEntryVer13 DEFAULT = new OFBsnVlanCounterStatsEntryVer13(
        DEFAULT_VLAN_VID, DEFAULT_VALUES
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnVlanCounterStatsEntryVer13(int vlanVid, List<U64> values) {
        if(values == null) {
            throw new NullPointerException("OFBsnVlanCounterStatsEntryVer13: property values cannot be null");
        }
        this.vlanVid = U16.normalize(vlanVid);
        this.values = values;
    }

    // Accessors for OF message fields
    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public List<U64> getValues() {
        return values;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFBsnVlanCounterStatsEntry.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnVlanCounterStatsEntry.Builder {
        final OFBsnVlanCounterStatsEntryVer13 parentMessage;

        // OF message fields
        private boolean vlanVidSet;
        private int vlanVid;
        private boolean valuesSet;
        private List<U64> values;

        BuilderWithParent(OFBsnVlanCounterStatsEntryVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public OFBsnVlanCounterStatsEntry.Builder setVlanVid(int vlanVid) {
        this.vlanVid = vlanVid;
        this.vlanVidSet = true;
        return this;
    }
    @Override
    public List<U64> getValues() {
        return values;
    }

    @Override
    public OFBsnVlanCounterStatsEntry.Builder setValues(List<U64> values) {
        this.values = values;
        this.valuesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFBsnVlanCounterStatsEntry build() {
                int vlanVid = this.vlanVidSet ? this.vlanVid : parentMessage.vlanVid;
                List<U64> values = this.valuesSet ? this.values : parentMessage.values;
                if(values == null)
                    throw new NullPointerException("Property values must not be null");

                //
                return new OFBsnVlanCounterStatsEntryVer13(
                    vlanVid,
                    values
                );
        }

    }

    static class Builder implements OFBsnVlanCounterStatsEntry.Builder {
        // OF message fields
        private boolean vlanVidSet;
        private int vlanVid;
        private boolean valuesSet;
        private List<U64> values;

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public OFBsnVlanCounterStatsEntry.Builder setVlanVid(int vlanVid) {
        this.vlanVid = vlanVid;
        this.vlanVidSet = true;
        return this;
    }
    @Override
    public List<U64> getValues() {
        return values;
    }

    @Override
    public OFBsnVlanCounterStatsEntry.Builder setValues(List<U64> values) {
        this.values = values;
        this.valuesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFBsnVlanCounterStatsEntry build() {
            int vlanVid = this.vlanVidSet ? this.vlanVid : DEFAULT_VLAN_VID;
            List<U64> values = this.valuesSet ? this.values : DEFAULT_VALUES;
            if(values == null)
                throw new NullPointerException("Property values must not be null");


            return new OFBsnVlanCounterStatsEntryVer13(
                    vlanVid,
                    values
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnVlanCounterStatsEntry> {
        @Override
        public OFBsnVlanCounterStatsEntry readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
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
            int vlanVid = U16.f(bb.readShort());
            // pad: 4 bytes
            bb.skipBytes(4);
            List<U64> values = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), U64.READER);

            OFBsnVlanCounterStatsEntryVer13 bsnVlanCounterStatsEntryVer13 = new OFBsnVlanCounterStatsEntryVer13(
                    vlanVid,
                      values
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnVlanCounterStatsEntryVer13);
            return bsnVlanCounterStatsEntryVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnVlanCounterStatsEntryVer13Funnel FUNNEL = new OFBsnVlanCounterStatsEntryVer13Funnel();
    static class OFBsnVlanCounterStatsEntryVer13Funnel implements Funnel<OFBsnVlanCounterStatsEntryVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnVlanCounterStatsEntryVer13 message, PrimitiveSink sink) {
            // FIXME: skip funnel of length
            sink.putInt(message.vlanVid);
            // skip pad (4 bytes)
            FunnelUtils.putList(message.values, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnVlanCounterStatsEntryVer13> {
        @Override
        public void write(ByteBuf bb, OFBsnVlanCounterStatsEntryVer13 message) {
            int startIndex = bb.writerIndex();
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeShort(U16.t(message.vlanVid));
            // pad: 4 bytes
            bb.writeZero(4);
            ChannelUtils.writeList(bb, message.values);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBsnVlanCounterStatsEntryVer13: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnVlanCounterStatsEntryVer13(");
        b.append("vlanVid=").append(vlanVid);
        b.append(", ");
        b.append("values=").append(values);
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
        OFBsnVlanCounterStatsEntryVer13 other = (OFBsnVlanCounterStatsEntryVer13) obj;

        if( vlanVid != other.vlanVid)
            return false;
        if (values == null) {
            if (other.values != null)
                return false;
        } else if (!values.equals(other.values))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + vlanVid;
        result = prime * result + ((values == null) ? 0 : values.hashCode());
        return result;
    }

}
