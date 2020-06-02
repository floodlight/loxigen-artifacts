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

class OFBsnArpIdleVer15 implements OFBsnArpIdle {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnArpIdleVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 24;

        private final static long DEFAULT_XID = 0x0L;
        private final static int DEFAULT_VLAN_VID = 0x0;
        private final static IPv4Address DEFAULT_IPV4_ADDR = IPv4Address.NONE;

    // OF message fields
    private final long xid;
    private final int vlanVid;
    private final IPv4Address ipv4Addr;
//
    // Immutable default instance
    final static OFBsnArpIdleVer15 DEFAULT = new OFBsnArpIdleVer15(
        DEFAULT_XID, DEFAULT_VLAN_VID, DEFAULT_IPV4_ADDR
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnArpIdleVer15(long xid, int vlanVid, IPv4Address ipv4Addr) {
        if(ipv4Addr == null) {
            throw new NullPointerException("OFBsnArpIdleVer15: property ipv4Addr cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.vlanVid = U16.normalize(vlanVid);
        this.ipv4Addr = ipv4Addr;
    }

    // Accessors for OF message fields
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public IPv4Address getIpv4Addr() {
        return ipv4Addr;
    }

    @Override
    public long getSubtype() {
        return 0x3cL;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public long getXid() {
        return xid;
    }



    public OFBsnArpIdle.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnArpIdle.Builder {
        final OFBsnArpIdleVer15 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean vlanVidSet;
        private int vlanVid;
        private boolean ipv4AddrSet;
        private IPv4Address ipv4Addr;

        BuilderWithParent(OFBsnArpIdleVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public IPv4Address getIpv4Addr() {
        return ipv4Addr;
    }

    @Override
    public OFBsnArpIdle.Builder setIpv4Addr(IPv4Address ipv4Addr) {
        this.ipv4Addr = ipv4Addr;
        this.ipv4AddrSet = true;
        return this;
    }
    @Override
    public long getSubtype() {
        return 0x3cL;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public OFBsnArpIdle.Builder setVlanVid(int vlanVid) {
        this.vlanVid = vlanVid;
        this.vlanVidSet = true;
        return this;
    }
    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBsnArpIdle.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }


        @Override
        public OFBsnArpIdle build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                int vlanVid = this.vlanVidSet ? this.vlanVid : parentMessage.vlanVid;
                IPv4Address ipv4Addr = this.ipv4AddrSet ? this.ipv4Addr : parentMessage.ipv4Addr;
                if(ipv4Addr == null)
                    throw new NullPointerException("Property ipv4Addr must not be null");

                //
                return new OFBsnArpIdleVer15(
                    xid,
                    vlanVid,
                    ipv4Addr
                );
        }

    }

    static class Builder implements OFBsnArpIdle.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean vlanVidSet;
        private int vlanVid;
        private boolean ipv4AddrSet;
        private IPv4Address ipv4Addr;

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public IPv4Address getIpv4Addr() {
        return ipv4Addr;
    }

    @Override
    public OFBsnArpIdle.Builder setIpv4Addr(IPv4Address ipv4Addr) {
        this.ipv4Addr = ipv4Addr;
        this.ipv4AddrSet = true;
        return this;
    }
    @Override
    public long getSubtype() {
        return 0x3cL;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public OFBsnArpIdle.Builder setVlanVid(int vlanVid) {
        this.vlanVid = vlanVid;
        this.vlanVidSet = true;
        return this;
    }
    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBsnArpIdle.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
//
        @Override
        public OFBsnArpIdle build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            int vlanVid = this.vlanVidSet ? this.vlanVid : DEFAULT_VLAN_VID;
            IPv4Address ipv4Addr = this.ipv4AddrSet ? this.ipv4Addr : DEFAULT_IPV4_ADDR;
            if(ipv4Addr == null)
                throw new NullPointerException("Property ipv4Addr must not be null");


            return new OFBsnArpIdleVer15(
                    xid,
                    vlanVid,
                    ipv4Addr
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnArpIdle> {
        @Override
        public OFBsnArpIdle readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 6
            byte version = bb.readByte();
            if(version != (byte) 0x6)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_15(6), got="+version);
            // fixed value property type == 4
            byte type = bb.readByte();
            if(type != (byte) 0x4)
                throw new OFParseError("Wrong type: Expected=OFType.EXPERIMENTER(4), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 24)
                throw new OFParseError("Wrong length: Expected=24(24), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            // fixed value property subtype == 0x3cL
            int subtype = bb.readInt();
            if(subtype != 0x3c)
                throw new OFParseError("Wrong subtype: Expected=0x3cL(0x3cL), got="+subtype);
            int vlanVid = U16.f(bb.readShort());
            // pad: 2 bytes
            bb.skipBytes(2);
            IPv4Address ipv4Addr = IPv4Address.read4Bytes(bb);

            OFBsnArpIdleVer15 bsnArpIdleVer15 = new OFBsnArpIdleVer15(
                    xid,
                      vlanVid,
                      ipv4Addr
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnArpIdleVer15);
            return bsnArpIdleVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnArpIdleVer15Funnel FUNNEL = new OFBsnArpIdleVer15Funnel();
    static class OFBsnArpIdleVer15Funnel implements Funnel<OFBsnArpIdleVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnArpIdleVer15 message, PrimitiveSink sink) {
            // fixed value property version = 6
            sink.putByte((byte) 0x6);
            // fixed value property type = 4
            sink.putByte((byte) 0x4);
            // fixed value property length = 24
            sink.putShort((short) 0x18);
            sink.putLong(message.xid);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x3cL
            sink.putInt(0x3c);
            sink.putInt(message.vlanVid);
            // skip pad (2 bytes)
            message.ipv4Addr.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnArpIdleVer15> {
        @Override
        public void write(ByteBuf bb, OFBsnArpIdleVer15 message) {
            // fixed value property version = 6
            bb.writeByte((byte) 0x6);
            // fixed value property type = 4
            bb.writeByte((byte) 0x4);
            // fixed value property length = 24
            bb.writeShort((short) 0x18);
            bb.writeInt(U32.t(message.xid));
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x3cL
            bb.writeInt(0x3c);
            bb.writeShort(U16.t(message.vlanVid));
            // pad: 2 bytes
            bb.writeZero(2);
            message.ipv4Addr.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnArpIdleVer15(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("vlanVid=").append(vlanVid);
        b.append(", ");
        b.append("ipv4Addr=").append(ipv4Addr);
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
        OFBsnArpIdleVer15 other = (OFBsnArpIdleVer15) obj;

        if( xid != other.xid)
            return false;
        if( vlanVid != other.vlanVid)
            return false;
        if (ipv4Addr == null) {
            if (other.ipv4Addr != null)
                return false;
        } else if (!ipv4Addr.equals(other.ipv4Addr))
            return false;
        return true;
    }

    @Override
    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFBsnArpIdleVer15 other = (OFBsnArpIdleVer15) obj;

        // ignore XID
        if( vlanVid != other.vlanVid)
            return false;
        if (ipv4Addr == null) {
            if (other.ipv4Addr != null)
                return false;
        } else if (!ipv4Addr.equals(other.ipv4Addr))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + vlanVid;
        result = prime * result + ((ipv4Addr == null) ? 0 : ipv4Addr.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + vlanVid;
        result = prime * result + ((ipv4Addr == null) ? 0 : ipv4Addr.hashCode());
        return result;
    }

}
