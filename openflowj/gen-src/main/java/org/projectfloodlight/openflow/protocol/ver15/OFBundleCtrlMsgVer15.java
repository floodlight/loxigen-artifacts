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

class OFBundleCtrlMsgVer15 implements OFBundleCtrlMsg {
    private static final Logger logger = LoggerFactory.getLogger(OFBundleCtrlMsgVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 16;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static long DEFAULT_XID = 0x0L;
        private final static Set<OFBundleFlags> DEFAULT_FLAGS = ImmutableSet.<OFBundleFlags>of();
        private final static List<OFBundleProp> DEFAULT_PROPERTIES = ImmutableList.<OFBundleProp>of();

    // OF message fields
    private final long xid;
    private final BundleId bundleId;
    private final OFBundleCtrlType bundleCtrlType;
    private final Set<OFBundleFlags> flags;
    private final List<OFBundleProp> properties;
//

    // package private constructor - used by readers, builders, and factory
    OFBundleCtrlMsgVer15(long xid, BundleId bundleId, OFBundleCtrlType bundleCtrlType, Set<OFBundleFlags> flags, List<OFBundleProp> properties) {
        if(bundleId == null) {
            throw new NullPointerException("OFBundleCtrlMsgVer15: property bundleId cannot be null");
        }
        if(bundleCtrlType == null) {
            throw new NullPointerException("OFBundleCtrlMsgVer15: property bundleCtrlType cannot be null");
        }
        if(flags == null) {
            throw new NullPointerException("OFBundleCtrlMsgVer15: property flags cannot be null");
        }
        if(properties == null) {
            throw new NullPointerException("OFBundleCtrlMsgVer15: property properties cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.bundleId = bundleId;
        this.bundleCtrlType = bundleCtrlType;
        this.flags = flags;
        this.properties = properties;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_CONTROL;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleCtrlType getBundleCtrlType() {
        return bundleCtrlType;
    }

    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public List<OFBundleProp> getProperties() {
        return properties;
    }



    public OFBundleCtrlMsg.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBundleCtrlMsg.Builder {
        final OFBundleCtrlMsgVer15 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bundleIdSet;
        private BundleId bundleId;
        private boolean bundleCtrlTypeSet;
        private OFBundleCtrlType bundleCtrlType;
        private boolean flagsSet;
        private Set<OFBundleFlags> flags;
        private boolean propertiesSet;
        private List<OFBundleProp> properties;

        BuilderWithParent(OFBundleCtrlMsgVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_CONTROL;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBundleCtrlMsg.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleCtrlMsg.Builder setBundleId(BundleId bundleId) {
        this.bundleId = bundleId;
        this.bundleIdSet = true;
        return this;
    }
    @Override
    public OFBundleCtrlType getBundleCtrlType() {
        return bundleCtrlType;
    }

    @Override
    public OFBundleCtrlMsg.Builder setBundleCtrlType(OFBundleCtrlType bundleCtrlType) {
        this.bundleCtrlType = bundleCtrlType;
        this.bundleCtrlTypeSet = true;
        return this;
    }
    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBundleCtrlMsg.Builder setFlags(Set<OFBundleFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public List<OFBundleProp> getProperties() {
        return properties;
    }

    @Override
    public OFBundleCtrlMsg.Builder setProperties(List<OFBundleProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }


        @Override
        public OFBundleCtrlMsg build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                BundleId bundleId = this.bundleIdSet ? this.bundleId : parentMessage.bundleId;
                if(bundleId == null)
                    throw new NullPointerException("Property bundleId must not be null");
                OFBundleCtrlType bundleCtrlType = this.bundleCtrlTypeSet ? this.bundleCtrlType : parentMessage.bundleCtrlType;
                if(bundleCtrlType == null)
                    throw new NullPointerException("Property bundleCtrlType must not be null");
                Set<OFBundleFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                List<OFBundleProp> properties = this.propertiesSet ? this.properties : parentMessage.properties;
                if(properties == null)
                    throw new NullPointerException("Property properties must not be null");

                //
                return new OFBundleCtrlMsgVer15(
                    xid,
                    bundleId,
                    bundleCtrlType,
                    flags,
                    properties
                );
        }

    }

    static class Builder implements OFBundleCtrlMsg.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bundleIdSet;
        private BundleId bundleId;
        private boolean bundleCtrlTypeSet;
        private OFBundleCtrlType bundleCtrlType;
        private boolean flagsSet;
        private Set<OFBundleFlags> flags;
        private boolean propertiesSet;
        private List<OFBundleProp> properties;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_CONTROL;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBundleCtrlMsg.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleCtrlMsg.Builder setBundleId(BundleId bundleId) {
        this.bundleId = bundleId;
        this.bundleIdSet = true;
        return this;
    }
    @Override
    public OFBundleCtrlType getBundleCtrlType() {
        return bundleCtrlType;
    }

    @Override
    public OFBundleCtrlMsg.Builder setBundleCtrlType(OFBundleCtrlType bundleCtrlType) {
        this.bundleCtrlType = bundleCtrlType;
        this.bundleCtrlTypeSet = true;
        return this;
    }
    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBundleCtrlMsg.Builder setFlags(Set<OFBundleFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public List<OFBundleProp> getProperties() {
        return properties;
    }

    @Override
    public OFBundleCtrlMsg.Builder setProperties(List<OFBundleProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
//
        @Override
        public OFBundleCtrlMsg build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            if(!this.bundleIdSet)
                throw new IllegalStateException("Property bundleId doesn't have default value -- must be set");
            if(bundleId == null)
                throw new NullPointerException("Property bundleId must not be null");
            if(!this.bundleCtrlTypeSet)
                throw new IllegalStateException("Property bundleCtrlType doesn't have default value -- must be set");
            if(bundleCtrlType == null)
                throw new NullPointerException("Property bundleCtrlType must not be null");
            Set<OFBundleFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            List<OFBundleProp> properties = this.propertiesSet ? this.properties : DEFAULT_PROPERTIES;
            if(properties == null)
                throw new NullPointerException("Property properties must not be null");


            return new OFBundleCtrlMsgVer15(
                    xid,
                    bundleId,
                    bundleCtrlType,
                    flags,
                    properties
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBundleCtrlMsg> {
        @Override
        public OFBundleCtrlMsg readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 6
            byte version = bb.readByte();
            if(version != (byte) 0x6)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_15(6), got="+version);
            // fixed value property type == 33
            byte type = bb.readByte();
            if(type != (byte) 0x21)
                throw new OFParseError("Wrong type: Expected=OFType.BUNDLE_CONTROL(33), got="+type);
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
            long xid = U32.f(bb.readInt());
            BundleId bundleId = BundleId.read4Bytes(bb);
            OFBundleCtrlType bundleCtrlType = OFBundleCtrlTypeSerializerVer15.readFrom(bb);
            Set<OFBundleFlags> flags = OFBundleFlagsSerializerVer15.readFrom(bb);
            List<OFBundleProp> properties = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFBundlePropVer15.READER);

            OFBundleCtrlMsgVer15 bundleCtrlMsgVer15 = new OFBundleCtrlMsgVer15(
                    xid,
                      bundleId,
                      bundleCtrlType,
                      flags,
                      properties
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bundleCtrlMsgVer15);
            return bundleCtrlMsgVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBundleCtrlMsgVer15Funnel FUNNEL = new OFBundleCtrlMsgVer15Funnel();
    static class OFBundleCtrlMsgVer15Funnel implements Funnel<OFBundleCtrlMsgVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBundleCtrlMsgVer15 message, PrimitiveSink sink) {
            // fixed value property version = 6
            sink.putByte((byte) 0x6);
            // fixed value property type = 33
            sink.putByte((byte) 0x21);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            message.bundleId.putTo(sink);
            OFBundleCtrlTypeSerializerVer15.putTo(message.bundleCtrlType, sink);
            OFBundleFlagsSerializerVer15.putTo(message.flags, sink);
            FunnelUtils.putList(message.properties, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBundleCtrlMsgVer15> {
        @Override
        public void write(ByteBuf bb, OFBundleCtrlMsgVer15 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 6
            bb.writeByte((byte) 0x6);
            // fixed value property type = 33
            bb.writeByte((byte) 0x21);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            message.bundleId.write4Bytes(bb);
            OFBundleCtrlTypeSerializerVer15.writeTo(bb, message.bundleCtrlType);
            OFBundleFlagsSerializerVer15.writeTo(bb, message.flags);
            ChannelUtils.writeList(bb, message.properties);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBundleCtrlMsgVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBundleCtrlMsgVer15(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("bundleId=").append(bundleId);
        b.append(", ");
        b.append("bundleCtrlType=").append(bundleCtrlType);
        b.append(", ");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("properties=").append(properties);
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
        OFBundleCtrlMsgVer15 other = (OFBundleCtrlMsgVer15) obj;

        if( xid != other.xid)
            return false;
        if (bundleId == null) {
            if (other.bundleId != null)
                return false;
        } else if (!bundleId.equals(other.bundleId))
            return false;
        if (bundleCtrlType == null) {
            if (other.bundleCtrlType != null)
                return false;
        } else if (!bundleCtrlType.equals(other.bundleCtrlType))
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (properties == null) {
            if (other.properties != null)
                return false;
        } else if (!properties.equals(other.properties))
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
        OFBundleCtrlMsgVer15 other = (OFBundleCtrlMsgVer15) obj;

        // ignore XID
        if (bundleId == null) {
            if (other.bundleId != null)
                return false;
        } else if (!bundleId.equals(other.bundleId))
            return false;
        if (bundleCtrlType == null) {
            if (other.bundleCtrlType != null)
                return false;
        } else if (!bundleCtrlType.equals(other.bundleCtrlType))
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (properties == null) {
            if (other.properties != null)
                return false;
        } else if (!properties.equals(other.properties))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((bundleId == null) ? 0 : bundleId.hashCode());
        result = prime * result + ((bundleCtrlType == null) ? 0 : bundleCtrlType.hashCode());
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((properties == null) ? 0 : properties.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((bundleId == null) ? 0 : bundleId.hashCode());
        result = prime * result + ((bundleCtrlType == null) ? 0 : bundleCtrlType.hashCode());
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((properties == null) ? 0 : properties.hashCode());
        return result;
    }

}
