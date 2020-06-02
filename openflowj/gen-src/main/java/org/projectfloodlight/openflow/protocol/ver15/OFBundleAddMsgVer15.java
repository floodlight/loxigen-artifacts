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

class OFBundleAddMsgVer15 implements OFBundleAddMsg {
    private static final Logger logger = LoggerFactory.getLogger(OFBundleAddMsgVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 23;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static long DEFAULT_XID = 0x0L;
        private final static Set<OFBundleFlags> DEFAULT_FLAGS = ImmutableSet.<OFBundleFlags>of();
        private final static List<OFBundleProp> DEFAULT_PROPERTIES = ImmutableList.<OFBundleProp>of();

    // OF message fields
    private final long xid;
    private final BundleId bundleId;
    private final Set<OFBundleFlags> flags;
    private final OFMessage message;
    private final List<OFBundleProp> properties;
//

    // package private constructor - used by readers, builders, and factory
    OFBundleAddMsgVer15(long xid, BundleId bundleId, Set<OFBundleFlags> flags, OFMessage message, List<OFBundleProp> properties) {
        if(bundleId == null) {
            throw new NullPointerException("OFBundleAddMsgVer15: property bundleId cannot be null");
        }
        if(flags == null) {
            throw new NullPointerException("OFBundleAddMsgVer15: property flags cannot be null");
        }
        if(message == null) {
            throw new NullPointerException("OFBundleAddMsgVer15: property message cannot be null");
        }
        if(properties == null) {
            throw new NullPointerException("OFBundleAddMsgVer15: property properties cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.bundleId = bundleId;
        this.flags = flags;
        this.message = message;
        this.properties = properties;
    }

    // Accessors for OF message fields
    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFMessage getData()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }

    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFMessage getMessage() {
        return message;
    }

    @Override
    public List<OFBundleProp> getProperties() {
        return properties;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_ADD_MESSAGE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public long getXid() {
        return xid;
    }



    public OFBundleAddMsg.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBundleAddMsg.Builder {
        final OFBundleAddMsgVer15 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bundleIdSet;
        private BundleId bundleId;
        private boolean flagsSet;
        private Set<OFBundleFlags> flags;
        private boolean messageSet;
        private OFMessage message;
        private boolean propertiesSet;
        private List<OFBundleProp> properties;

        BuilderWithParent(OFBundleAddMsgVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleAddMsg.Builder setBundleId(BundleId bundleId) {
        this.bundleId = bundleId;
        this.bundleIdSet = true;
        return this;
    }
    @Override
    public OFMessage getData()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }

    @Override
    public OFBundleAddMsg.Builder setData(OFMessage data) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }
    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBundleAddMsg.Builder setFlags(Set<OFBundleFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public OFMessage getMessage() {
        return message;
    }

    @Override
    public OFBundleAddMsg.Builder setMessage(OFMessage message) {
        this.message = message;
        this.messageSet = true;
        return this;
    }
    @Override
    public List<OFBundleProp> getProperties() {
        return properties;
    }

    @Override
    public OFBundleAddMsg.Builder setProperties(List<OFBundleProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
    @Override
    public OFType getType() {
        return OFType.BUNDLE_ADD_MESSAGE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBundleAddMsg.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }


        @Override
        public OFBundleAddMsg build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                BundleId bundleId = this.bundleIdSet ? this.bundleId : parentMessage.bundleId;
                if(bundleId == null)
                    throw new NullPointerException("Property bundleId must not be null");
                Set<OFBundleFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                OFMessage message = this.messageSet ? this.message : parentMessage.message;
                if(message == null)
                    throw new NullPointerException("Property message must not be null");
                List<OFBundleProp> properties = this.propertiesSet ? this.properties : parentMessage.properties;
                if(properties == null)
                    throw new NullPointerException("Property properties must not be null");

                //
                return new OFBundleAddMsgVer15(
                    xid,
                    bundleId,
                    flags,
                    message,
                    properties
                );
        }

    }

    static class Builder implements OFBundleAddMsg.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bundleIdSet;
        private BundleId bundleId;
        private boolean flagsSet;
        private Set<OFBundleFlags> flags;
        private boolean messageSet;
        private OFMessage message;
        private boolean propertiesSet;
        private List<OFBundleProp> properties;

    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleAddMsg.Builder setBundleId(BundleId bundleId) {
        this.bundleId = bundleId;
        this.bundleIdSet = true;
        return this;
    }
    @Override
    public OFMessage getData()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }

    @Override
    public OFBundleAddMsg.Builder setData(OFMessage data) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }
    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBundleAddMsg.Builder setFlags(Set<OFBundleFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public OFMessage getMessage() {
        return message;
    }

    @Override
    public OFBundleAddMsg.Builder setMessage(OFMessage message) {
        this.message = message;
        this.messageSet = true;
        return this;
    }
    @Override
    public List<OFBundleProp> getProperties() {
        return properties;
    }

    @Override
    public OFBundleAddMsg.Builder setProperties(List<OFBundleProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
    @Override
    public OFType getType() {
        return OFType.BUNDLE_ADD_MESSAGE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBundleAddMsg.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
//
        @Override
        public OFBundleAddMsg build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            if(!this.bundleIdSet)
                throw new IllegalStateException("Property bundleId doesn't have default value -- must be set");
            if(bundleId == null)
                throw new NullPointerException("Property bundleId must not be null");
            Set<OFBundleFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            if(!this.messageSet)
                throw new IllegalStateException("Property message doesn't have default value -- must be set");
            if(message == null)
                throw new NullPointerException("Property message must not be null");
            List<OFBundleProp> properties = this.propertiesSet ? this.properties : DEFAULT_PROPERTIES;
            if(properties == null)
                throw new NullPointerException("Property properties must not be null");


            return new OFBundleAddMsgVer15(
                    xid,
                    bundleId,
                    flags,
                    message,
                    properties
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBundleAddMsg> {
        @Override
        public OFBundleAddMsg readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 6
            byte version = bb.readByte();
            if(version != (byte) 0x6)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_15(6), got="+version);
            // fixed value property type == 34
            byte type = bb.readByte();
            if(type != (byte) 0x22)
                throw new OFParseError("Wrong type: Expected=OFType.BUNDLE_ADD_MESSAGE(34), got="+type);
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
            // pad: 1 bytes
            bb.skipBytes(1);
            Set<OFBundleFlags> flags = OFBundleFlagsSerializerVer15.readFrom(bb);
            OFMessage message = OFMessageVer15.READER.readFrom(bb);
            List<OFBundleProp> properties = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFBundlePropVer15.READER);

            OFBundleAddMsgVer15 bundleAddMsgVer15 = new OFBundleAddMsgVer15(
                    xid,
                      bundleId,
                      flags,
                      message,
                      properties
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bundleAddMsgVer15);
            return bundleAddMsgVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBundleAddMsgVer15Funnel FUNNEL = new OFBundleAddMsgVer15Funnel();
    static class OFBundleAddMsgVer15Funnel implements Funnel<OFBundleAddMsgVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBundleAddMsgVer15 message, PrimitiveSink sink) {
            // fixed value property version = 6
            sink.putByte((byte) 0x6);
            // fixed value property type = 34
            sink.putByte((byte) 0x22);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            message.bundleId.putTo(sink);
            // skip pad (1 bytes)
            OFBundleFlagsSerializerVer15.putTo(message.flags, sink);
            message.message.putTo(sink);
            FunnelUtils.putList(message.properties, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBundleAddMsgVer15> {
        @Override
        public void write(ByteBuf bb, OFBundleAddMsgVer15 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 6
            bb.writeByte((byte) 0x6);
            // fixed value property type = 34
            bb.writeByte((byte) 0x22);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            message.bundleId.write4Bytes(bb);
            // pad: 1 bytes
            bb.writeZero(1);
            OFBundleFlagsSerializerVer15.writeTo(bb, message.flags);
            message.message.writeTo(bb);
            ChannelUtils.writeList(bb, message.properties);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBundleAddMsgVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBundleAddMsgVer15(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("bundleId=").append(bundleId);
        b.append(", ");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("message=").append(message);
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
        OFBundleAddMsgVer15 other = (OFBundleAddMsgVer15) obj;

        if( xid != other.xid)
            return false;
        if (bundleId == null) {
            if (other.bundleId != null)
                return false;
        } else if (!bundleId.equals(other.bundleId))
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (message == null) {
            if (other.message != null)
                return false;
        } else if (!message.equals(other.message))
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
        OFBundleAddMsgVer15 other = (OFBundleAddMsgVer15) obj;

        // ignore XID
        if (bundleId == null) {
            if (other.bundleId != null)
                return false;
        } else if (!bundleId.equals(other.bundleId))
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (message == null) {
            if (other.message != null)
                return false;
        } else if (!message.equals(other.message))
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
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((message == null) ? 0 : message.hashCode());
        result = prime * result + ((properties == null) ? 0 : properties.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((bundleId == null) ? 0 : bundleId.hashCode());
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((message == null) ? 0 : message.hashCode());
        result = prime * result + ((properties == null) ? 0 : properties.hashCode());
        return result;
    }

}
